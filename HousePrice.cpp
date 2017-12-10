// File: HousePrice
// Created by Hugo Valle on 11/22/2017.
// Copyright (c) 2017 WSU
//

#include "HousePrice.h"

/**
 * Default constructor for HousePrice
 */
HousePrice::HousePrice()
{

}

/**
 * Constructor with arguments for HousePrice
 * @param id
 * @param number
 * @param street
 * @param city
 * @param state
 * @param postalCode
 * @param price
 */
HousePrice::HousePrice(int id, int number, const string &street, const string &city, const string &state,
                       int postalCode, double price)
{
    HousePrice::id = id;
    HousePrice::number = number;
    HousePrice::street = street;
    HousePrice::city = city;
    HousePrice::state = state;
    HousePrice::postalCode = postalCode;
    HousePrice::price = price;
}

/**
 * Getter for price in HousePrice
 * @return : price
 */
double HousePrice::getPrice() const
{
    return price;
}

/**
 * Getter for state in HousePrice
 * @return : state
 */
const string &HousePrice::getState() const
{
    return state;
}

/**
 * Output operator for HousePrice
 * @param os : Output function
 * @param price : Class object to be displayed
 * @return : All class values as output
 */
ostream &operator<<(ostream &os, const HousePrice &price)
{
    os << "id: " << price.id << " ";
    os << "number: " << price.number << " ";
    os << "postalCode: " << price.postalCode << " ";
    os << "street: " << price.street << " ";
    os << "city: " << price.city << " ";
    os << "state: " << price.getState() << " ";
    os << "price: " << price.getPrice();
    return os;
}
