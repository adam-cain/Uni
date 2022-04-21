//
// Coded by Prudence Wong 2022-03-13
//
// Name: Adam Cain
// Student ID: 201572027
// University email address: sgacain2@liverpool.ac.uk
//
// Time Complexity and explanation:
// n denotes the number of vertices
//
//
// neighbourhood(): O(2n) due to a nested for loop, one looping through every line in the adjanceny matrix and the second
// looping a diffrent DFS for each node
//
//
class COMP108A2Graph {
  // input parameter: an integer distance
  // output: compute neighbourhood matrix for distance 
  static int[][]neibourMatrix;
  static COMP108A2Output neighbourhood(int[][] adjMatrix, int gSize) {
    COMP108A2Output output = new COMP108A2Output(1, gSize);
    neibourMatrix = new int[gSize][gSize];
    DFS(adjMatrix, gSize);
    output.neighbourMatrix = neibourMatrix;
    return output;
  }

  static void DFS(int[][] adjMatrix, int gSize){
    for (int i = 0; i < gSize; i++) {
      _DFS(adjMatrix, gSize, i, i, 0);
    }
  }

  static void _DFS(int[][] adjMatrix, int gSize, int start, int curr, int depth){
    if(depth >= gSize){return;}
    if(neibourMatrix[start][curr] == 0 && start != curr || depth < neibourMatrix[start][curr]){
      addEdge(depth, start, curr);
    }
    depth++;
    for (int i = 0; i < gSize; i++) {
        if(adjMatrix[curr][i] == 1){
            _DFS(adjMatrix, gSize,start, i, depth);
        }
    }
    return;
  }

  public static void addEdge(int distance, int x, int y){
    neibourMatrix[x][y] = distance;
    neibourMatrix[y][x] = distance;
  }


  // DO NOT change this method, you can use it if you want
  static void printSquareArray(int array[][], int size) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        System.out.print(array[i][j] + " ");
      }
      System.out.println();
    }
  }
}