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

	struct FORM {
		enum Type{
			I = 0,
			O,
			S,
			Z,
			J,
			L,
			T,
			NONE,
		};
	};

	Block(void);
	~Block(void);
	void Init(void);
	void UpData(void);
	void Draw(void);

	void Status(STATUS::Type);
	STATUS::Type Status(void);

	void BlockType(Block::FORM::Type);
	Block::FORM::Type BlockType(void);

private:
	typedef GameObject base;
	STATUS::Type status;
	Block::FORM::Type  blockType;
};

