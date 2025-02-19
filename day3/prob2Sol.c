void countVotes(int votes[], int n, int candidateVotes[]) {
    for(int I = 0; I < n; I++) {
        candidateVotes[votes[I]-1]++;
    }
}
int findWinner(int candidateVotes[]) {
    int max_index = 0;
    for(int I = 1; I < 5; I++) {
        if(candidateVotes[I] > candidateVotes[max_index]) {
            max_index = I;
        }
    }
    return max_index + 1;
}