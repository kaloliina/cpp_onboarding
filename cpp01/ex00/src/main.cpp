#include "../include/Zombie.hpp"
/*..Allocating on the stack or heap.
- The stack is a region of memory that stores local variables
and function call info.
- It happens automatically when declaring variables in a function.
- Doesn't need new or delete.

- The heap is a region of memory for dynamic allocation that persists
until you explicitly free it.
- Needs new and delete.

So for example if I had a function where I created a zombie on stack
and I attempted to return it, I would be returning the address
of a dead object. So heap allocation lets the object persist
beyond the function in which it was created.
*/
int main(void)
{
	Zombie *Zombie = newZombie("Sylvanas");
	Zombie->announce();
	randomChump("Jaina");
	delete Zombie;
	return (0);
}
