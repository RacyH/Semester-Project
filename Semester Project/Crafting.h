#ifndef CRAFTING_H
#define CRAFTING_H


class Crafting
{
public:

	void craftitem();
	void craftworld();

private:
	int itemtype[16][1]; //The second option will have a max of 1, and it will determine whether or not you are able to craft the item. so 0 means no, 1 means yes
	int worldtype[3][1];
};

#endif //CRAFTING_H
