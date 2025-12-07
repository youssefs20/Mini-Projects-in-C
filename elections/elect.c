#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9


int preferences[MAX_VOTERS][MAX_CANDIDATES];

int current_rank[MAX_VOTERS];


typedef struct
{
    char name[50];
    int votes;
    bool eliminated;
} candidate;

candidate candidates[MAX_CANDIDATES];

int voter_count;
int candidate_count;

// Function prototypes
bool vote_func(int voter, int rank, char *name);
void tabulate(void);
bool print_winner(void);
int find_min(void);

bool is_final_tie(int min_votes); 
void eliminate(int min);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %d\n", MAX_CANDIDATES);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        strcpy(candidates[i].name, argv[i + 1]);
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    printf("Number of voters: ");
    scanf("%d", &voter_count);
    getchar();

    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %d\n", MAX_VOTERS);
        return 3;
    }

    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            char input[50];

            while (true)
            {
                printf("Voter %d, Rank %d: ", i + 1, j + 1);
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';
                if (vote_func(i, j, input))
                {
                    break;
                }
                printf("Invalid vote. Please enter a valid candidate name.\n");
            }
        }

        printf("\n");
        current_rank[i] = 0;
    }

    while (true)
    {

        tabulate();

        if (print_winner())
        {
            break;
        }

        int min = find_min();


        if (is_final_tie(min))
        {
            printf("\nElection ends in a tie between the remaining candidates:\n");
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("- %s\n", candidates[i].name);
                }
            }
            break; 
        }


        eliminate(min);
    }
    return 0;
}


//returns true if candidate name is valid.
bool vote_func(int voter, int rank, char *name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i; 
            return true;
        }
    }
    return false;
}

// counts votes each voter votes for their highest rank not eliminated candidate
void tabulate(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].votes = 0;
    }

    for (int i = 0; i < voter_count; i++)
    {
        for (int j = current_rank[i]; j < candidate_count; j++)
        {
            int c = preferences[i][j];

            if (!candidates[c].eliminated)
            {
                candidates[c].votes++;
                break;
            }
        }
    }
}


// checks if any candidate has >50% of votes has the majority 
//and returns true if winner found.
bool print_winner(void)
{
    int half = voter_count / 2;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > half)  // Needs majority to win
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }

    return false;
}


int find_min(void)
{
    int min = voter_count + 1;

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < min)
        {
            min = candidates[i].votes;  // Track lowest vote count
        }
    }

    return min;
}


// detects final tie
bool is_final_tie(int min_votes)
{
    int remaining_candidates = 0;
    int candidates_at_min = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            remaining_candidates++;
            if (candidates[i].votes == min_votes)
            {
                candidates_at_min++;
            }
        }
    }
    
    // tie if all remaining candidates have equal votes
    return remaining_candidates > 1 && candidates_at_min == remaining_candidates;
}


// eliminates all candidates with minimum votes
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min && !candidates[i].eliminated)
        {
            candidates[i].eliminated = true;
        }
    }
}
