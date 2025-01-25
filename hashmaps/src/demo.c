#include "hashmap.h"

// Drivers code
int main()
{
	// Initialize the value of mp
	struct HashMap *mp = calloc(1, sizeof(struct HashMap));
	initialize_hashmap(mp);

	insert(mp, "Yogaholic", "Anjali");
	insert(mp, "pluto14", "Vartika");
	insert(mp, "elite_Programmer", "Manish");
	insert(mp, "decentBoy", "Mayank");

	printf("%s\n", search(mp, "elite_Programmer"));
	printf("%s\n", search(mp, "Yogaholic"));
	printf("%s\n", search(mp, "pluto14"));
	printf("%s\n", search(mp, "decentBoy"));

	// Key is not inserted
	printf("%s\n", search(mp, "randomKey"));

	printf("\nAfter deletion : \n");

	// Deletion of key
	delete_node(mp, "decentBoy");
	printf("%s\n", search(mp, "decentBoy"));

    clean_up(mp);
	return 0;
}
