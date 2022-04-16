#!/bin/bash

echo "**********************"
echo "* Tests for dthproxy *"
echo "**********************"
echo ""
echo ""
echo "---------------------------------------------------------------------"
echo "Running the program with full command line arguments :"
echo ""
g++ dthproxy.cpp -o dthproxy && ./dthproxy --input_interface YYY --input_interface_ipcidr KKK --output_interface XXX

echo "---------------------------------------------------------------------"
echo "Running the program with alternate command line arguments :"
echo ""
g++ dthproxy.cpp -o dthproxy && ./dthproxy -i YYY -c KKK -o XXX

echo "---------------------------------------------------------------------"
echo "Running the program with --help: "
echo ""
g++ dthproxy.cpp -o dthproxy && ./dthproxy --help

echo "---------------------------------------------------------------------"
echo "Running the program with wrong arguments: "
echo ""
g++ dthproxy.cpp -o dthproxy && ./dthproxy -i YYY -c KKK -x XXX

echo "---------------------------------------------------------------------"
echo "Running the program without arguments: "
echo ""
g++ dthproxy.cpp -o dthproxy && ./dthproxy
