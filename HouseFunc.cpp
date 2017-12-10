// File: HouseFunc
// Created by Hugo Valle on 11/22/2017.
// Copyright (c) 2017 WSU
//

#include <iostream>
#include <vector>
#include <map>
#include "HouseFunc.h"
#include "HousePrice.h"
#include "csv.h" // library to read csv files
#include <algorithm>

using namespace std;

/*!
 * Read CSV Mock Data. Parses each record in the file to
 * an object of HousePrice house. Then, populate a vector
 * of HousePrice objects with all the records.
 * It uses special library to parse CSV file "csv.h"
 * @param fileIn File name <string>
 * @param hp Reference to Vector of HousePrice Objects
 */
void readCSV(const string fileIn,vector<HousePrice>& hp)
{
    io::CSVReader<7> in(fileIn);
    in.read_header(io::ignore_extra_column, "id", "number", "street", "city", "state", "postalCode", "price");
    int id;
    int number;
    string street;
    string city;
    string state;
    int postalCode;
    double price;
    while(in.read_row(id, number, street, city, state, postalCode, price))
    {
        HousePrice hp1(id,number,street,city,state,postalCode,price);
        cout << hp1 << endl;
        hp.push_back(hp1);
    }
}


/*!
 * Sort the Vector of HousePrice Objects by price. Display the most affordable
 * and the most expensive house from the vector.
 * @param hp Reference to vector<HousePrice>
 */
void houseMarketValues(vector<HousePrice> &hp)
{
    // Sort by Price
    vector<double> vPrice;
    for (unsigned int i = 0; i < hp.size(); i++)
    {
        vPrice.push_back(hp[i].getPrice());
    }

    auto minVal = min_element(begin(vPrice), end(vPrice));
    for (auto item:hp)
    {
        if (item.getPrice() == *minVal)
        {
            cout << "Most Affordable Home: " << item << endl;
        }
    }

    auto maxVal = max_element(begin(vPrice), end(vPrice));
    for (auto item:hp)
    {
        if (item.getPrice() == *maxVal)
        {
            cout << "Most Expensive Home: " << item << endl;
        }
    }
}


/*!
 * Sort the Vector of HousePrice Objects by state. Display the
 * number of houses per state.
 * It uses a map to count instances per state.
 * @param hp Reference to vector<HousePrice>
 */
void houseMarketPerState(vector<HousePrice> &hp)
{
    // Sort by State
    map<string, int> MarketState;

    vector<string> states;
    vector<string> uniqueStates;
    vector<int> stateIndex;

    for (unsigned int i = 0; i < hp.size(); i++)
    {
        states.push_back(hp[i].getState());
    }
    sort(states.begin(), states.end());
    uniqueStates.push_back(states[0]);
    stateIndex.push_back(1);

    for (unsigned int i = 1; i < states.size(); i++)
    {
        if (states[i] == states[i-1])
        {
            stateIndex[stateIndex.size()-1] += 1;
        }
        else
        {
            uniqueStates.push_back(states[i]);
            stateIndex.push_back(1);
        }
    }
    for (unsigned int i = 0; i < uniqueStates.size(); i++)
    {
        MarketState[uniqueStates[i]] = stateIndex[i];
    }
    int j = 0;
    for (auto ip = MarketState.begin(); ip != MarketState.end(); ip++)
    {
        cout << ip->first << " " << ip->second << "     ";
        j++;
        if ((j == 10) || (j == 20) || (j == 30) || (j == 40) || (j == 50))
        {
            cout << endl;
        }
    }
}
