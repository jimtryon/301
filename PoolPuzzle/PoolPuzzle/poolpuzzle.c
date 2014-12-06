//
//  poolpuzzle.c
//  PoolPuzzle
//
//  Created by Jim Tryon on 12/5/14.
//  Copyright (c) 2014 Jim Tryon. All rights reserved.
//
// The program has two functions: one that prints out catalog information
// and the other that prints out the label.

#include <stdio.h>

/* Print out the catalog entry */
void catalog(const char *name, const char *species, int teeth, int age)
{
    printf("%s is a %s with %i teeth.  He is %i\n",
           name, species, teeth, age);
    
}

/* Print the label for the tank */
void label(const char *name, const char *species, int teeth, int age)
{
    printf("Name:%s\nSpecies:%s\n%i years old, %i teeth\n",
           name, species, age, teeth);
}

int main(int argc, const char * argv[]) {
    catalog("Snappy", "Pirahna", 69, 4);
    label("Snappy", "Pirahna", 69, 4);
}





