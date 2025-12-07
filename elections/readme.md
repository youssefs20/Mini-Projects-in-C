## Runoff Election System

## This program implements the preferential voting system known as Instant Runoff Voting (IRV) to determine the winner who commands the broadest support among the electorate.

### Key features

-   Preferential Voting: Allows voters to rank candidates by preference (1st, 2nd, 3rd, etc.).

-   Progressive Elimination: Conducts successive voting rounds, eliminating the candidate with the fewest votes in each round.

-   Vote Transfer: Votes cast for an eliminated candidate are automatically transferred to the voter's next-highest ranked candidate
    who has not yet been eliminated.

-   Majority Winner Determination: The election ends when one candidate secures more than 50% of the votes.

-   Final Tie Detection: The program detects a final tie (where all remaining candidates have an equal number of votes) and declares a tie instead of continuing elimination.

---

### How to run

1. Compilation

Use the gcc compiler or any other C compiler to compile the file:

```Bash
gcc -o runoff elect.c
```

2. Execution

Candidate names must be passed as **command-line arguments** when running the program.

```Bash
./runoff [Candidate 1] [Candidate 2] [Candidate 3] ...
```

Example:

```Bash
./runoff youssef ali ahmed
```

3. Voter Input

The program will first prompt you for the total number of voters, and then ask each voter to input their ranked preferences using the candidate names:

```bash
Number of voters: 3
Voter 1, Rank 1: youssef
Voter 1, Rank 2: ali
Voter 1, Rank 3: ahmed

Voter 2, Rank 1: ahmed
Voter 2, Rank 2: youssef
Voter 2, Rank 3: ali

Voter 3, Rank 1: ahmed
Voter 3, Rank 2: ali
Voter 3, Rank 3: youssef
```

# The counting and elimination process then begins until a winner is announced.

---

#### System Constraints

-   Maximum Candidates (MAX_CANDIDATES): 9 candidates.

-   Maximum Voters (MAX_VOTERS): 100 voters.

-   Candidate names must be entered accurately (case-sensitive matching).

---

### Overview of Core Functions

| Function | Description |

---

| main |The entry point. It handles reading candidate names, receiving voter input, and managing the rounds of elimination.|
| vote_func | Validates the candidate name and stores the preference (candidate index) in the preferences array.|
| tabulate | Counts the votes in each round, crediting each voter's vote to their highest-ranked, non-eliminated candidate.|
| print_winner | Checks if any candidate has secured a majority (>50%) of the votes.|
| find_min | Finds the minimum number of votes received by any remaining candidate.|
| is_final_tie | Detects a final tie by checking if all remaining candidates have the exact same number of votes.|
| eliminate | Sets the eliminated flag to true for all candidates receiving the minimum number of votes.|
