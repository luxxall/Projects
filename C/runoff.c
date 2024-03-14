#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }
//check if eliminated status is considered
//candidates[1].eliminated = true;
//candidates[2].eliminated = true;

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

//check if votes are counted correctly and pause
//printf("name:%s-votes:%i, name:%s-votes:%i, name:%s-votes:%i, name:%s-votes:%i\n", candidates[preferences[0][0]].name, candidates[preferences[0][0]].votes, candidates[preferences[0][1]].name, candidates[preferences[0][1]].votes, candidates[preferences[0][2]].name, candidates[preferences[0][2]].votes, candidates[preferences[0][3]].name, candidates[preferences[0][3]].votes);
//int stop = get_int("PAUZA");

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

//check for find min to concern eliminated status
//candidates[2].eliminated = true;

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

//check for min output
//printf("\nmin: %i\n", min);
//int stop = get_int("PAUZA");

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    bool result;
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i;
            result = true;
        }
    }
    return result;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int choice = 0; choice < candidate_count; choice++)
        {
            if (candidates[preferences[i][choice]].eliminated == false)
            {
                candidates[preferences[i][choice]].votes += 1;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int result = false;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > voter_count / 2)
        {
            printf("%s\n", candidates[i].name);
            result = true;
        }
    }
    return result;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min = candidates[0].votes;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < min && candidates[i].eliminated == false)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    bool result = true;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            if (candidates[i].votes != min)
            {
                result = false;
            }
        }
    }
    return result;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min && candidates[i].eliminated == false)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}