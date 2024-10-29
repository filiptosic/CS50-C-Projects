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


    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();


        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

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
    // loop through every candidate until a matching name is found
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            // assign index of that name to where the voter has ranked them
            preferences[voter][rank] = i;
            // return true to show a matching name has been found
            return true;
        }

    }
    // if for loop executes without hitting its return true statement, false will be returned meaning name entered was not a match
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // loop through each voter
    for (int i = 0; i < voter_count; i++)
    {
        // then through each of the voter's preferences
        for (int k = 0; k < candidate_count; k++)
        {
            // check if voter's preference is still in the race
            if (candidates[preferences[i][k]].eliminated == false)
            {
                // if so, add 1 to their tally and exit the inner loop so you can continue to their next preference
                candidates[preferences[i][k]].votes++;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // declare a variable which will store the highest number of votes
    int most_votes = 0;
    // declare a variable which will check if someone achieves a majority (total/2)
    float enough_to_win = (float)voter_count / 2;
    // loop through all the candidates and check who has the most votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > most_votes)
        {
            most_votes = candidates[i].votes;
        }
    }

    // if someone has achieved enough to win, print winner. Else don't print anything and return false
    if (!(most_votes > enough_to_win))
    {
        return false;
    }
    else
        // compare all candidates to the max number of votes to find their name
    {
        for (int k = 0; k < candidate_count; k++)
        {
            if (candidates[k].votes == most_votes)
            {
                printf("%s\n", candidates[k].name);
            }
        }
        return true;
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // set a minimum to check against. Use voter count to establish the maximum anyone could get
    int min = candidates[0].votes;
    // check who is below maximum. If they are update the min variable to be their vote count
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes < min)
        {
            min = candidates[i].votes;
        }
    }
    // TODO
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    for (int i = 0; i < candidate_count - 1; i++)
    {
        // check if any two candidates have differing votes. if so break loop immediately and return false
        if (candidates[i].votes != min && candidates[i].eliminated == false)
        {

            return false;
        }


    }
    // if for loop executes all the way through it means all candidates had the same amount of votes, so return true
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // loop through candidates array and check if they have the minimum number of votes
        if (candidates[i].votes == min)
        {
            // if candidate has the minimum number of votes, update their status to be eliminated
            candidates[i].eliminated = true;
        }
    }
    return;
}