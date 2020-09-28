#ifndef Block_H
#define Block_H

class Block {
private:
	int blockID;
	int start;
	int end;
	int size;
	bool busy;
public:
	Block(int blockID, int start, int end);
	int getBlockID();
	int	getStart();
	int	getEnd();
	int	getSize();
	bool getBusy();
	void setBlockID(int blockID);
	void setStart(int start);
	void setEnd(int end);
	void setSize(int size);
	void setBusy(bool busy);
};


#endif // !Block_H
