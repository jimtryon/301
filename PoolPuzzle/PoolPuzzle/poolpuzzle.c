//
//  poolpuzzle.c
//  PoolPuzzle
//
//  Created by Jim Tryon on 12/5/14.
//  Copyright (c) 2014 Jim Tryon. All rights reserved.
//
// The program is an example of structs that has two functions:
// one that prints out catalog information and the other that
// prints out the label.

#include <stdio.h>
struct fish {
    const char *name;
    const char *species;
    int teeth;
    int age;
};

/* Print out the catalog entry */
void catalog(struct fish f)
{
    printf("%s is a %s with %i teeth.  He is %i\n",
           f.name, f.species, f.teeth, f.age);
    
}

/* Print the label for the tank */
void label(struct fish f)
{
    printf("Name:%s\nSpecies:%s\n%i years old, %i teeth\n",
           f.name, f.species, f.teeth, f.age);
}

int main(int argc, const char * argv[]) {
    struct fish snappy = {"Snappy", "Pirahna", 4, 69};
    catalog(snappy);
    label(snappy);
    
    return 0;
}





