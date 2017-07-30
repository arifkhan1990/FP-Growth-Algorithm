
/*----------------------------------------------------------------------------------------------------------------------------------------\\
|                                                                                                                                          |
|                                             Name           : ARIF KHAN NIHAR                                                             |
|                                             E_mail         : arifkhanshubro@gmail.com                                                    |
|                                             github_link    : https://github.com/arifkhan1990                                             |
|                                             Problem        : Implementation of FP-Growth Algorithm in C++                                |
|                                             Date           : 26/07/2017                                                                  |
|                                             Subject_ref    : Data Mining                                                                 |
|                                             Execution Time : 0.042s                                                                      |
|                                             My Blog link :   https://arif778.blogspot.com/                                               |
|                                                                                                                                          |
|                                                     -----   -----   -----                                                                |
|                                                     |^_^|   |^_^|   |^_^|                                                                |                                                                                                                                          |
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include<bits/stdc++.h>
using namespace std;

//sorted by high to low in second value
template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return ((a.second != b.second)? a.second > b.second : a.first < b.first);
    }
};
//sorted by low to high in first value
template <typename T1, typename T2>
struct greater_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return ((a.second != b.second)? a.second < b.second : a.first > b.first);
    }
};
//tree display
void Tree_LeftPatteren(int n,string st,int t){
    if(n == 0){
        cout << "\t\t\t\t\t  /\n";
        cout << "\t\t\t\t\t /\n";
        cout << "\t\t\t\t\t/\n";
        cout << "\t\t\t\t    " << st << " : " << t << " \n";
    }else if(n == 1){
        cout << "\t\t\t\t      /\n";
        cout << "\t\t\t\t     /\n";
        cout << "\t\t\t\t    /\n";
        cout << "\t\t\t\t" << st << " : " << t << " \n";
    }else if(n == 2){
        cout << "\t\t\t          /\n";
        cout << "\t\t\t         /\n";
        cout << "\t\t\t        /\n";
        cout << "\t\t\t    " << st << " : " << t << " \n";
    }else if(n == 3){
        cout << "\t\t\t      /\n";
        cout << "\t\t\t     /\n";
        cout << "\t\t\t    /\n";
        cout << "\t\t\t" << st << " : " << t << " \n";
    }else if( n == 4){
        cout << "\t\t      /\n";
        cout << "\t\t     /\n";
        cout << "\t\t    /\n";
        cout << "\t\t\t" << st << " : " << t << " \n";
    }
}

string data[10][10][10],database[10][10];
int t_transaction,maximum_purchase_item,minimum_support;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    freopen("input1.txt","r",stdin);
    //freopen("output1.txt","w",stdout);

   // "Enter Transaction Number : " ;
    cin >> t_transaction ;
    // "Enter Maximum Purchase Item : " ;
    cin >> maximum_purchase_item;
    // "Enter Minimum Support : " ;
    cin >> minimum_support;

    cout << "Transaction Number : " << t_transaction << endl << "Maximum Purchase Item : "
    << maximum_purchase_item << endl << "Minimum Support : " << minimum_support << endl << endl;
   //take uesr input
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
    //show the Data
    cout << "Purchase Data (Database): " << endl;
        for(int i = 0; i < t_transaction ; i++){
        cout << data[i][0][0] << " :  ";
        for(int j = 1 ; j <= maximum_purchase_item; j++ ){
        cout << " " << data[i][i+1][j] ;
        }
        cout << endl;
    }
    cout << endl;
    //calculet and display Freguency Of Occurrence
    vector<pair<string,int> > order(sorting_data.begin(),sorting_data.end());
    sort(order.begin(),order.end(), less_second<string, int>());
    vector<pair<string, int> >:: iterator it = order.begin();
    map<string, int>:: iterator it1;

    vector<pair<string,int> >sort_low_value(sorting_data.begin(),sorting_data.end());
    sort(sort_low_value.begin(),sort_low_value.end(), greater_second<string, int>());

    cout << "Freguency Of Occurrence :" << endl;
    cout << "------------------------------------|\n";
    cout << " Item   |  Frequency | \t  Priority  |\n";
    cout << "------------------------------------|\n";
    for(it1 = sorting_data.begin(); it1 != sorting_data.end(); it1++, it++){
            input2 = it->first;
        cout << "  " <<it1->first << "    |      " << it1->second << "     |\t     " << input2[1] << "\t    |\n";
    cout << "------------------------------------|\n";
    }
    //Calculate Frequent item list
    int i1 = 0;
    cout << "\nFrequent item list of 'L'  : \n L = { " ;
    for(it = order.begin(); it != order.end(); it++,i1++){
        cout << it->first << " : " << it->second ;
        cout << ((i1+1 == order.size())? " }" : " , ");
    }
    cout << endl << endl;
    //create sorted and unsorted transaction table draw
    vector<pair<string,int> >order_set;
    cout << "Order the item table according to priority :" << endl;
    cout << "----------------------------------------------------|\n";
    cout << " TID   |   List of items ID's   |   Order items     |\n";
    cout << "----------------------------------------------------|\n";
    for(int i = 0, j2 ; i < t_transaction ; i++){
        cout << "  " << data[i][0][0] << " ";
        order_set.clear();
        for(int j = 1 ; j <= maximum_purchase_item; j++ ){
        cout << ((j==1)?"  |       ":" ") << data[i][i+1][j] ;
        order_set.push_back(pair<string,int>(data[i][i+1][j],sorting_data.find(data[i][i+1][j])->second));
        }
        cout << "   \t|   ";
        sort(order_set.begin(),order_set.end(), less_second<string, int>());
        vector<pair<string, int> >:: iterator it = order_set.begin();
         j2 = 0;
        for(;it != order_set.end(); it++,j2++){
             cout << it->first << " ";
             database[i][j2] = it->first;
        }
        database[i][j2] = "*";
        cout << " \t \n----------------------------------------------------|\n";
    }
    //Create Tree patteren each transaction
    map<string,int> tree_time_count;
    for(int i1 = 0; i1 < t_transaction ; i1++){
    cout << endl << "For Trnsaction : ";
      for(int j1 = 0; database[i1][j1] != "*" ; j1++){
        cout << database[i1][j1] << " ";
      }
      cout << endl;
      cout << "  FP - Tree : \n";
      cout << "\t\t\t\t\t null or { }   \n";

      for(int j1 = 0,p = 0; database[i1][j1] != "*" ; j1++){
          string sd = database[i1][j1];
          tree_time_count[sd]++;
            if(!sd.empty()){
                  Tree_LeftPatteren(p,sd,tree_time_count.find(sd)->second);
                 p++;
            }
      }
      cout << endl;
    }
    //// Store data for Contitional Base Patteren item's
    map<pair<string,string>, int> best_Result;
    map<pair<string,string>, int> FP_tree;

    int k1 = 1,tl = 0;
    map<string,int>conditional_FP_tree_DataStore;
    vector<string>temporaryData;
    set<string>t_temporaray;
    for(vector<pair<string,int> >::iterator ip = sort_low_value.begin(); ip != sort_low_value.end() - 1 ; ip++,tl++){
        for(int h1 = 0, k1 = 1; h1 < t_transaction ; h1++, k1++){
         for(int h2 = 0; h2 < maximum_purchase_item and database[h1][h2] != "*"; h2++ ){
                temporaryData.push_back(database[h1][h2]);
                t_temporaray.insert(database[h1][h2]);
          }
         int k2 = 1 ;
          if(t_temporaray.count(ip->first) != 0)
              {
                  string Cpb = "";
                  for(vector<string>::iterator h3 = temporaryData.begin(); h3 !=  temporaryData.end()   ; h3++,k2++){
                        if ((*h3) == ip->first) break;
                    if(!(*h3).empty()){
                    conditional_FP_tree_DataStore[*h3]++;
                      Cpb +=  ((!Cpb.empty())? "," + (*h3) : (*h3));
                    }
                  }
                  if(!Cpb.empty()){
                      best_Result[make_pair(ip->first,Cpb)]++;
                  }
              }
         temporaryData.clear();
         t_temporaray.clear();
        }

        map<string, int>:: iterator ir = conditional_FP_tree_DataStore.begin();
        vector<pair<string,int> > order3(conditional_FP_tree_DataStore.begin(),conditional_FP_tree_DataStore.end());
        sort(order3.begin(),order3.end(), greater_second<string, int>());
        vector<pair<string, int> >:: iterator irt = order3.begin();

         for(; irt != order3.end() ; irt++){
            if(irt->second >= minimum_support)
                 FP_tree[make_pair(ip->first,irt->first)] = irt->second;
         }
         conditional_FP_tree_DataStore.clear();
    }
    cout << endl;
//// calculate Contional Base Patteren item
    map<pair<string,string>,int>::iterator ipu = best_Result.end();
    ipu--;

for(vector<pair<string,int> >::iterator ip = sort_low_value.begin(); ip != sort_low_value.end()-1; ip++){
            cout << "Conditional Base Patteren for " << ipu->first.first << " : ";
            bool b = false;
    for(; ; ipu--){
            if(ipu->first.first != ip->first ) {
                cout << endl;
                    break;
            }
            else if(b) cout << " , ";
            cout << "{ " << ipu->first.second  << " : " << ipu->second << " }" ;
            b = true;
            if(ipu == best_Result.begin())break;
      }
    }
    cout << endl << endl;
// Store data for Contitional FP-Tree item
    map<pair<string,string>,int>::iterator ipu1 = FP_tree.end();
    ipu1--;

    ipu = best_Result.end();
    ipu--;

    it = order.begin();

    map< string , int>orginal_result;
    map< pair<string,string> , int > output;

for(vector<pair<string,int> >::iterator ip = sort_low_value.begin(); ip != sort_low_value.end()-1; ip++){
    for(; ; ipu--){
            if(ipu->first.first != ip->first ) {
            break;
            }
            if(ipu->second >= minimum_support){
            orginal_result.insert(make_pair(ipu->first.second,ipu->second));
            output[make_pair(ipu->first.first,ipu->first.second)] = ipu->second;
            }
               if(ipu == best_Result.begin())break;
    }
        for(; ; ipu1--){
            if(ipu1->first.first != ip->first ) {
            break;
            }

        if(ipu1->second >= minimum_support){
            if(orginal_result.count(ipu1->first.second) != 0){
                if(ipu1->first.second != it->first)
                    output[make_pair(ipu1->first.first,ipu1->first.second)] = ((ipu1->second < orginal_result.find(ipu1->first.second)->second)?ipu1->second : orginal_result.find(ipu1->first.second)->second);
                    else output[make_pair(ipu1->first.first,ipu1->first.second)] = ipu1->second;
            }else output[make_pair(ipu1->first.first,ipu1->first.second)] = ipu1->second;
        }
        if(ipu1 == FP_tree.begin())break;
    }
    orginal_result.clear();
}

cout << endl;
// calculate Contional FP-Tree item
map< pair<string,string> , int >:: iterator op = output.end();
op--;

for(vector<pair<string,int> >::iterator ip = sort_low_value.begin(); ip != sort_low_value.end()-1; ip++){
            cout << "Conditional FR - Tree for " << ip->first << " : ";
            bool b = false;
    for(; ; op--){
            if(op->first.first != ip->first ) {
                cout << endl;
                    break;
            }
            else if(b) cout << " , ";
            cout << "{ " << op->first.second  << " : " << op->second << " }" ;
            b = true;
            if(op == output.begin())break;
      }
    }
    cout << endl << endl;

    // Calculate Frequent Item Set

    set<string>test;
    op = output.end();
    op--;
    string fg,gh;

    cout << "Frequent Item's Patteren : " << endl;

    for(vector<pair<string,int> >::iterator ip = sort_low_value.begin(); ip != sort_low_value.end()-1; ip++){
            int min_value = 1001;
            cout << ip->first << " <---------> ";
            bool b = false;
    for(; ; op--){
            if(op->first.first != ip->first ) {
                if(test.count(gh) == 0)
                    cout << " { " << gh << "," <<  ip->first << " : " << min_value << " } " ;
                cout << endl;

                gh.clear();
                    break;
            }
            else if(b) cout << "  ";
            fg = op->first.second;

            if(fg.size() == 2)
                gh += ((!gh.empty())? ","+ op->first.second : op->first.second);

            test.insert(fg);
            cout << "{ " << op->first.second << "," << op->first.first << " : " << op->second << " }" ;
            min_value = min(min_value,op->second);
            b = true;
            if(op == output.begin())break;
      }
    }
    cout << endl;
    cout << "\n\n \t\t\t\t\t\t THANK YOU \n";
    return 0;
}

