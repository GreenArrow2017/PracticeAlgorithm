//
// Created by GreenArrow on 2020/4/9.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

map<string, vector<int>> keyWords_id;

class book {
public:
    int ID;
    string title;
    vector<string> keyWords;
    string author;
    string publisher;
    string publish_year;

    book() { keyWords.clear(); }

    book(int id, const string &title, const vector<string> &keyWords, const string &author, const string &publisher,
         const string &publishYear) : ID(id), title(title), keyWords(keyWords), author(author), publisher(publisher),
                                      publish_year(publishYear) {}
};

vector<string> getKeyWords(string keyWords, int id) {
    vector<string> keywords_contain;
    string result;
    for (int i = 0; i < keyWords.size(); ++i) {
        if (keyWords[i] != ' ') {
            result += keyWords[i];
        } else {
            keywords_contain.push_back(result);
            if (keyWords_id.count(result) > 0) {
                keyWords_id[result].push_back(id);
            } else {
                vector<int> ids;
                ids.push_back(id);
                keyWords_id[result] = ids;
            }
            result = "";
        }
    }
    keywords_contain.push_back(result);
    if (keyWords_id.count(result) > 0) {
        keyWords_id[result].push_back(id);
    } else {
        vector<int> ids;
        ids.push_back(id);
        keyWords_id[result] = ids;
    }
    return keywords_contain;
}

void print_vector(vector<int> ids) {
    if (ids.size() == 0) {
        cout << "Not Found" << endl;
        return;
    }
    for (int i = 0; i < ids.size(); ++i) {
        printf("%07d\n", ids[i]);
    }
}

int main() {
    vector<book> books;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int id;
        string title;
        string author;
        string keyWords_string;
        string publisher;
        string publish_year;
        cin >> id;
        cin.ignore();
        getline(cin, title);
        getline(cin, author);
        getline(cin, keyWords_string);
        getline(cin, publisher);
        cin >> publish_year;
        cin.ignore();
        vector<string> keyWords = getKeyWords(keyWords_string, id);
        book Book(id, title, keyWords, author, publisher, publish_year);
        books.push_back(Book);
    }

    int m;
    cin >> m;
    cin.ignore();
    for (int j = 0; j < m; ++j) {
        vector<int> result;
        string query;
        getline(cin, query);
        char flag = query[0];
        string target = query.substr(3, query.size() - 3);
        if (flag == '1') {
            for (int i = 0; i < books.size(); ++i) {
                if (books[i].title == target) {
                    result.push_back(books[i].ID);
                }
            }
            sort(result.begin(), result.end());
        } else if (flag == '2') {
            for (int i = 0; i < books.size(); ++i) {
                if (books[i].author == target) {
                    result.push_back(books[i].ID);
                }
            }
            sort(result.begin(), result.end());
        } else if (flag == '3') {
            result = keyWords_id[target];
            sort(result.begin(), result.end());
        } else if (flag == '4') {
            for (int i = 0; i < books.size(); ++i) {
                if (books[i].publisher == target) {
                    result.push_back(books[i].ID);
                }
            }
            sort(result.begin(), result.end());
        } else if (flag == '5') {
            for (int i = 0; i < books.size(); ++i) {
                if (books[i].publish_year == target) {
                    result.push_back(books[i].ID);
                }
            }
            sort(result.begin(), result.end());
        }

        cout << query << endl;
        print_vector(result);
    }
}