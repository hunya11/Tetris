#pragma once
class Block : public GameObject
{
public:	
	struct STATUS {
		enum Type{
			NONE = 0,
			FIX,
			MOVE,
			GHOST,
		};
	};

	Block(void);
	~Block(void);
	void Init(void);
	void UpData(void);
	void Draw(void);

	void Status(STATUS::Type);
	STATUS::Type Status(void);

	void BlockType(BLOCK::Type);
	BLOCK::Type BlockType(void);

private:
	typedef GameObject base;
	STATUS::Type status;
	BLOCK::Type  blockType;
};

