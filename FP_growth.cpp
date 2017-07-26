
/*----------------------------------------------------------------------------------------------------------------------------------------\\
|                                                                                                                                          |
|                                             Name           : ARIF KHAN NIHAR                                                             |
|                                             E_mail         : arifkhanshubro@gmail.com                                                    |
|                                             github_link    : https://github.com/arifkhan1990                                             |
|                                             Problem        : Implementation of FP-Growth Algorithm in C++                                |
|                                             Date           : 26/07/2017                                                                  |
|                                             Subject_ref    : Data Mining                                                                 |
|                                             Execution Time : 0.019s                                                                      |
|                                                                                                                                          |
|                                                                                                                                          |
|                                                                                                                                          |
|                                             My Blog link :   https://arif778.blogspot.com/                                               |
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include<bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second > b.second;
    }
};

string data[10][10][10];
int t_transaction,maximum_purchase_item,minimum_support;

int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(NULL);
    freopen("input1.txt","r",stdin);
    //freopen("output1.txt","w",stdout);

   // cout << "Enter Transaction Number : " ;
    cin >> t_transaction ;
    //cout << endl << "Enter Maximum Purchase Item : " ;
    cin >> maximum_purchase_item;
    //cout << endl;
    //cout << "Enter Minimum Support : " ;
    cin >> minimum_support;
    //cout << endl;
    cout << "Transaction Number : " << t_transaction << endl << "Maximum Purchase Item : " << maximum_purchase_item << endl << "Minimum Support : " << minimum_support << endl << endl;

    string input,input2;
    map<string, int>sorting_data;
    int i = 0;
    for(int i = 0; i < t_transaction ; i++){
        cin >> data[i][0][0];
        for(int j = 1 ; j <= maximum_purchase_item; j++ ){
            cin >> input;
            if(input == "*") break;
            data[i][i+1][j] = input;
            sorting_data[input]++;

        }
    }

    cout << "Purchase Data (Database): " << endl;
        for(int i = 0; i < t_transaction ; i++){
        cout << data[i][0][0] << " :  ";
        for(int j = 1 ; j <= maximum_purchase_item; j++ ){
        cout << " " << data[i][i+1][j] ;
        }
        cout << endl;
    }
    cout << endl;
    vector<pair<string,int> > order(sorting_data.begin(),sorting_data.end());
    sort(order.begin(),order.end(), less_second<string, int>());
    vector<pair<string, int> >:: iterator it = order.begin();
    map<string, int>:: iterator it1;

    cout << "Freguency Of Occurrence :" << endl;
    cout << "------------------------------------|\n";
    cout << " Item   |  Frequency | \t  Priority  |\n";
    cout << "------------------------------------|\n";
    for(it1 = sorting_data.begin(); it1 != sorting_data.end(); it1++, it++){
            input2 = it->first;
        cout << "  " <<it1->first << "    |      " << it1->second << "     |\t     " << input2[1] << "\t    |\n";
    cout << "------------------------------------|\n";
    }
    int i1 = 0;
    cout << "\nFrequent item list of 'L'  : \n L = { " ;
    for(it = order.begin(); it != order.end(); it++,i1++){
        cout << it->first << " : " << it->second ;
        cout << ((i1+1 == order.size())? " }" : " , ");
    }
    cout << endl;
    return 0;
}

