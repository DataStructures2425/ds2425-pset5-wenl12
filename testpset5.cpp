#include "problems.h"
#include <vector>
using namespace std;

int main()
{
    /*
    // TEST YOUR CODE HERE... no really - test it!
    cout << "cache :(" << endl;
    LRUCache c = LRUCache(1);
    c.put(1, 1);
    cout << c.get(1) << endl;
    cout << c.get(2) << endl;
    c.put(3, 3);
    cout << c.get(4) << endl;
    cout << c.get(3) << endl;
    c.put(6, 6);
    c.put(2, 2);
    cout << c.get(2) << endl;
    cout << c.get(6) << endl;
    cout << c.get(3) << endl;
    c.put(5, 5);
    cout << c.get(2) << endl;
    cout << c.get(6) << endl;
    cout << c.get(5) << endl;

    cout << "new" << endl;
    c = LRUCache(4);
    c.put(1, 1);
    c.put(3, 3);
    c.put(5, 5);
    c.put(6, 6);
    c.put(2, 2);
    cout << c.get(1) << endl;
    cout << c.get(2) << endl;
    c.put(7, 7);
    cout << c.get(3) << endl;
    cout << c.get(7) << endl;
    cout << c.get(5) << endl;
    c.put(1, 1);
    cout << c.get(6) << endl;
    cout << c.get(7) << endl;
    cout << c.get(1) << endl;
    c.put(5, 5);
    cout << c.get(9) << endl;
    cout << c.get(2) << endl;

    cout << "new" << endl;
    c = LRUCache(0);

    cout << "new" << endl;
    c = LRUCache(5);
    c.put(1, 1);
    c.put(10, 10);
    c.put(5, 5);
    c.put(6, 6);
    c.put(2, 2);
    c.put(11, 11);
    c.put(12, 12);
    c.put(4, 4);
    cout << c.get(1) << endl;
    cout << c.get(2) << endl;
    cout << c.get(4) << endl;
    cout << c.get(11) << endl;
    cout << c.get(1) << endl;
    cout << c.get(6) << endl;
    c.put(6, 6);
    c.put(3, 3);
    c.put(1, 1);
    cout << c.get(1) << endl;
    cout << c.get(11) << endl;
    cout << c.get(6) << endl;
    cout << c.get(3) << endl;
    cout << c.get(10) << endl;
    cout << c.get(8) << endl;
    c.put(1, 2);
    c.put(3, 6);
    cout << c.get(1) << endl;
    cout << c.get(3) << endl;
    cout << endl;


    cout << "rearranging fruits" << endl;
    vector<int> basket1 = {1, 3, 4, 9};
    vector<int> basket2 = {1, 3, 4, 9};
    
    cout << minCost(basket1, basket2) << endl;
    basket1 = {1, 2, 5, 9};
    cout << minCost(basket1, basket2) << endl;
    basket1 = {1, 2, 3};
    basket2 = {1, 2, 4};
    cout << minCost(basket1, basket2) << endl;
    basket1 = {1};
    basket2 = {2};
    cout << minCost(basket1, basket2) << endl;
    basket1 = {1, 5, 3, 6};
    basket2 = {6, 3, 5, 1};
    cout << minCost(basket1, basket2) << endl;
    basket1 = {1, 3, 1};
    basket2 = {2, 3, 2};
    cout << minCost(basket1, basket2) << endl;
    basket1 = {1, 4};
    basket2 = {4, 1};
    cout << minCost(basket1, basket2) << endl;
    basket1 = {3, 4};
    basket2 = {3, 3};
    cout << minCost(basket1, basket2) << endl;
    
    basket1 = {10, 5, 3, 10};
    basket2 = {6, 5, 3, 6};
    cout << "6 " << minCost(basket1, basket2) << endl;
    basket1 = {10, 3, 3, 10};
    basket2 = {6, 5, 5, 6};
    cout << "8 " << minCost(basket1, basket2) << endl;
    basket1 = {10, 3, 3, 10, 1, 8, 8, 1};
    basket2 = {6, 5, 5, 6, 2, 2, 9, 9};
    cout << "11 " << minCost(basket1, basket2) << endl;
    basket1 = {10, 3, 3, 10, 3, 3};
    basket2 = {6, 5, 5, 6, 6, 6};
    cout << "11 " << minCost(basket1, basket2) << endl;
    basket1 = {1, 1, 1};
    basket2 = {1, 1, 1};
    cout << minCost(basket1, basket2) << endl;
    basket1 = {5, 5, 1};
    basket2 = {1, 1, 5};
    cout << minCost(basket1, basket2) << endl;
    basket1 = {1, 3, 1};
    basket2 = {2, 1, 1};
    cout << minCost(basket1, basket2) << endl;
    cout << endl;
*/

    cout << "sudoku..............." << endl;
    vector<vector<char>> board = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSudoku(board);
    board = {
    {'1', '9', '2', '.', '.', '7', '.', '4', '5'}, 
    {'.', '.', '.', '.', '.', '3', '8', '.', '1'},
    {'8', '.', '.', '.', '1', '4', '.', '.', '9'},
    {'.', '.', '5', '.', '3', '.', '6', '.', '.'},
    {'.', '2', '1', '.', '5', '.', '.', '.', '7'},
    {'.', '4', '.', '7', '6', '.', '.', '.', '.'},
    {'4', '7', '.', '3', '.', '5', '.', '.', '.'},
    {'.', '.', '8', '9', '.', '.', '7', '5', '.'},
    {'3', '.', '.', '8', '.', '1', '4', '9', '.'}};
    solveSudoku(board);
    board = {
    {'.', '.', '.', '3', '.', '.', '.', '.', '.'}, 
    {'2', '5', '3', '.', '.', '.', '4', '.', '.'},
    {'.', '6', '.', '.', '.', '2', '7', '8', '.'},
    {'.', '.', '.', '.', '.', '1', '6', '.', '8'},
    {'4', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'9', '.', '.', '8', '4', '.', '.', '1', '.'},
    {'7', '.', '.', '2', '.', '3', '.', '.', '.'},
    {'.', '.', '.', '1', '.', '7', '5', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '9'}};
    solveSudoku(board);
    board = {
    {'4', '.', '.', '3', '.', '.', '5', '7', '.'}, 
    {'.', '.', '.', '.', '.', '6', '.', '2', '4'},
    {'9', '.', '.', '.', '.', '5', '.', '.', '.'},
    {'7', '.', '.', '8', '4', '.', '.', '.', '3'},
    {'.', '.', '.', '.', '.', '2', '.', '9', '.'},
    {'.', '.', '8', '6', '.', '.', '.', '.', '2'},
    {'1', '6', '7', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '3', '.', '6'},
    {'2', '.', '.', '.', '.', '.', '.', '.', '.'}};
    solveSudoku(board);
    board = {
    {'9', '1', '3', '.', '.', '.', '5', '.', '.'}, 
    {'6', '.', '7', '.', '.', '.', '.', '2', '4'},
    {'.', '5', '.', '.', '8', '.', '.', '7', '.'},
    {'.', '7', '9', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '2', '.', '9', '.', '.', '4', '3'},
    {'.', '.', '.', '.', '.', '4', '.', '9', '.'},
    {'.', '4', '.', '.', '.', '1', '9', '.', '.'},
    {'7', '.', '6', '.', '.', '9', '.', '.', '5'},
    {'.', '.', '1', '.', '.', '6', '4', '.', '7'}};
    solveSudoku(board);
}