//
// Created by meshi on 13/01/2020.
//

#include "StringReverser.h"
#include <bits/stdc++.h>
using namespace std;
string StringReverser::solve(string str) {
  reverse(str.begin(), str.end());
    return str;
}