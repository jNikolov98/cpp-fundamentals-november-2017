/*
    Write a class Sale holding the following data: town, product, price, quantity. Read a list of sales and calculate and
    print the total sales by town as shown in the output. Order the towns alphabetically in the output.
*/

#include <iostream>
#include <map>

using namespace std;

struct Sale {
    string town;
    string product;
    double prise;
    double quantity;
};

int main()
{
    int n;
    map<string, double> prisePerTown;
    cin >> n;
    Sale sales[5];
    for(int i = 0; i < n; i++)
    {
        cin >> sales[i].town >> sales[i].product >> sales[i].prise >> sales[i].quantity;
        prisePerTown[sales[i].town] += sales[i].prise * sales[i].quantity;
    }
    for(auto i = prisePerTown.begin(); i != prisePerTown.end(); i++)
    {
        cout << i->first << " -> " << i->second << endl;
    }

}
