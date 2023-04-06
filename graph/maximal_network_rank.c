// Helper function to check if two cities have a road between them
bool hasRoad(int city1, int city2, int** roads, int roadsSize) {
    for (int i = 0; i < roadsSize; i++) {
        if ((roads[i][0] == city1 && roads[i][1] == city2) || (roads[i][0] == city2 && roads[i][1] == city1)) {
            return true;
        }
    }
    return false;
}

int maximalNetworkRank(int n, int** roads, int roadsSize, int* roadsColSize){
    int maxRank = 0;
    int degrees[n];

    // Initialize degrees array to count the number of roads for each city
    memset(degrees, 0, sizeof(degrees));
    for (int i = 0; i < roadsSize; i++) {
        degrees[roads[i][0]]++;
        degrees[roads[i][1]]++;
    }

    // Iterate through all pairs of cities and calculate their network rank
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int rank = degrees[i] + degrees[j];
            if (hasRoad(i, j, roads, roadsSize)) {
                rank--;
            }
            maxRank = fmax(maxRank, rank);
        }
    }

    return maxRank;
}
