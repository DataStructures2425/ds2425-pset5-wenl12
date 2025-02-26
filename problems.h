#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <iterator>
using namespace std;


// PROBLEM 1 - LRU CACHE

class LRUCache {
public:
    struct Node{
        Node* next;
        Node* prev;
        int val;
        int keyy;
    };
    Node* head;
    Node* tail;
    int numOfNodes = 0;
    int max;
    unordered_map<int, Node*> m;
    LRUCache(int capacity) {
        if (capacity <= 3000 && capacity >= 1){
            head = nullptr;
            tail = nullptr;
            max = capacity;
        } else {
            cout << "nu uh" << endl;
        }
    }
    
    int get(int key) {
        if (m.find(key) != m.end()){
            Node* n = m[key];
            if (n == nullptr) return -1;
            if (head == tail || n->prev == nullptr){
                return n->val;
            } 
            if (n->next == nullptr){
                head = head->prev;
                head->next = nullptr;
                n->next = tail;
                tail->prev = n;
                tail = n;
                return n->val;
            }
            Node* b = n->prev;
            Node* a = n->next;
            a->prev = b;
            b->next = a;
            tail->prev = n;
            n->next = tail;
            tail = n;
            return n->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (value >= 0 && value <= 100000){
            Node* newNode = new Node();
            newNode->val = value;
            newNode->keyy = key;
            if (head == nullptr){
                head = newNode;
                tail = head;
                numOfNodes++;
            } else if (head == tail){
                if (numOfNodes >= max){
                    Node* byeBye = head;
                    m.erase(byeBye->keyy);
                    delete(byeBye);
                    head = newNode;
                    tail = head;
                } else{
                    Node* goofy = tail;
                    tail->prev = newNode;
                    newNode->next = tail;
                    head = goofy;
                    tail = newNode;
                    numOfNodes++;
                }
            } else if (m[key] != nullptr){
                Node* why = m[key];
                why->val = value;
                if (why->next == nullptr){
                    Node* pls = head;
                    head = head->prev;
                    delete(pls);
                    head->next = nullptr;
                    tail->prev = why;
                    why->next = tail;
                    tail = why;
                } else if (why->prev != nullptr){
                    Node* b = why->prev;
                    Node* a = why->next;
                    a->prev = b;
                    b->next = a;
                    tail->prev = why;
                    why->next = tail;
                    tail = why;
                }
            } else {
                tail->prev = newNode;
                newNode->next = tail;
                tail = newNode;
                numOfNodes++;
                if (numOfNodes > max){
                    Node* goodbye = head;
                    m.erase(goodbye->keyy);
                    Node* newH = head->prev;
                    delete(goodbye);
                    head = newH;
                    newH->next = nullptr;
                    numOfNodes--;
                }
            }
            m[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// PROBLEM 2 - REARRANGING FRUITS

long long minCost(vector<int>& basket1, vector<int>& basket2) 
{
    map<int, int> m;
    //value (key) and amount 
    for (int i : basket1){
        if (m.find(i) != m.end()) m[i]++;
        else m[i] = 1;
    }
    for (int j : basket2){
        if (m.find(j) != m.end()) m[j]--;
        else m[j] = -1;
    }
    for (auto i = m.begin(); i != m.end(); i++){
        //cout << i->first << " " << i->second << endl;
        if (i->second % 2 != 0) return -1;
    }
    //return 0;
    int cost = 0;
    int change1 = -1;
    int change2 = -1;
    for (auto it = m.begin(); it != m.end(); ++it){
        //cout << "l" << it->first << endl;
        int num = it->first;
        if (m[num] != 0){
            if (change1 == -1){
                change1 = num;
                if (m[num] < 0){
                    //cout << "a" << endl;
                    m[num] += 2;
                    for (auto it2 = m.rbegin(); it2 != m.rend(); ++it2){
                        if (it2->second > 0 && change2 == -1){
                            //cout << "b" << endl;
                            m[it2->first] -= 2;
                            change2 = it2->first;
                            break;
                        }
                    }  
                } else {
                    m[num] -= 2;
                    for (auto it3 = m.rbegin(); it3 != m.rend(); ++it3){
                        //cout << "a" << endl;
                        if (it3->second < 0 && change2 == -1){
                            m[it3->first] += 2;
                            change2 = it3->first;
                            break;
                        }
                    }  
                }
            }
        }
        //cout << cost << " " << change1 << " " << change2 << endl;
        if (change1 != -1 && change2 != -1){
            cost += min(change1, change2);
            change1 = -1;
            change2 = -1;
        }
    }
    return cost;
}
int li;
int lj;
bool original[9][9];

bool backtracking(vector<vector<char>>& board, int index1, int index2){
    if (!original[li][lj]) return true;
    if (original[index1][index2]){
        for (int i = 1; i < 10; i++){
            //cout << i<<endl;
            bool yahOrNah = true;
            if (find(board[index1].begin(), board[index1].end(), i+'0') != board[index1].end()) yahOrNah = false;
            for (int j = 0; j < 9; j++){
                if (board[j][index2] == i+'0') {
                    yahOrNah = false;
                }
            }
            for (int k = index1/3*3; k < index1/3*3 + 3; k++){
                for (int l = index2/3*3; l < index2/3*3 + 3; l++){
                    if (board[k][l] == i+'0'){
                        yahOrNah = false;
                    } 
                }
            }
            if (yahOrNah){
                //cout << "HERE" << endl;
                board[index1][index2] = i+'0';
                original[index1][index2] = false;
                if (index2 == 8){
                    if (backtracking(board, index1+1, 0)) return true;
                } else {
                    if (backtracking(board, index1, index2+1)) return true;
                }
            }
        }
        //cout << "a"<<index1 << " " << index2 << endl;
        board[index1][index2] = '.';
        original[index1][index2] = true;
        return false;
        
    } else {
        //cout << index1 << " " << index2 << endl;
        if (index2 == 8){
            if (backtracking(board, 1+index1, 0)) return true;
        } else {
            if (backtracking(board, index1, 1+index2)) return true;
        }
    }
    return false;
}


// PROBLEM 3 - SUDOKU SOLVER

// Hint - it would probably be helpful to write a function that
// print out the board for you!

void solveSudoku(vector<vector<char>>& board) 
{
    cout << "a" << endl;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (board[i][j] != '.') original[i][j] = false;
            else{
                original[i][j] = true;
                li = i;
                lj = j;
            } 
        }
    }
    cout << li << " " << lj << endl;
    backtracking(board, 0, 0);

    for (int k = 0; k < 9; k++){
        for (int l = 0; l < 9; l++){
            cout << board[k][l] << " ";
        }
        cout << endl;
    }
}