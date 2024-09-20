#!/bin/bash

# Define the recipe you want to remove
recipe_to_remove="recipe-name" # Replace with the actual recipe name

# Remove the specified recipe from the list
sed -i "/$recipe_to_remove/d" pn-buildlist

# Loop through each recipe in pn-buildlist and build it
while read -r recipe; do
    bitbake "$recipe"
done < pn-buildlist

