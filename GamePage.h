#pragma once
class GamePage : public Page
{
private:

	struct SCORE_POINT{
		enum Point{
			LINE1 = 100,
			LINE2 = 250,
			LINE3 = 625,
			LINE4 = 1500,
		};
	};

	// Summary : �e�N���X
	typedef Page base;

	// Summary : �u���b�N
	Block* block[20][10];

	Block* hold[4][3];

	Block* stock[3][4][3];
	
	// Summary : �~�m
	struct MINO{
		// Summary : x���W
		int x;
		// Summary : y���W
		int y;
		// Summary : �`
		BLOCK::Type type;
	};
	
	// Summary : ���삷��~�m
	MINO mino[4];

	// Summary : ���삷��~�m�̃S�[�X�g
	MINO ghost[4];

	// Summary : ���ԑ҂��~�m�̌`
	BLOCK::Type minoNextStock[3];
	
	// Summary : �z�[���h�����~�m�̌`
	BLOCK::Type minoHold;

	// Summary : �����Ǘ�
	RandomNum* rand;
	
	// Summary : �~�m���ڒn���Ă��邩
	bool isGrounding;
	
	// Summary : �A�C�h���^�C������
	bool isIdletime;
	
	// Summary : �n�[�h�h���b�v���g���Ă邩
	bool isHardDrop;
	
	// Summary : �~�m�������邩
	bool isCanMove;
	
	// Summary : �~�m���������
	bool isSpin;
	
	// Summary : �z�[���h���g������
	bool isHold;
	
	// Summary : ���łɃz�[���h���Ă��邩
	bool isAlreadyHold;
	
	// Summary : 
	int OldIdleSeconds;
	
	// Summary : 
	int OldDropSeconds;
	
	// Summary : �A�C�h���^�C���̍ő厞��
	int IdleMax;
	
	// Summary : �����ҋ@�̍ő厞��
	int DropMax;

	// Summary : ���Ƃ����u���b�N�̕��z
	int dropBlock[7];

	// Summary : �X�R�A
	int numScore;

	//�I�v�V����
	bool isOptionMinoDrop;

	bool isOptionDrawGMino;

	bool isOptionUseHardDrop;

	bool isOptionUseSpin;

	bool isOptionUseHold;

	bool isOptionShowNext;

	Effect* eff;
	vector<Effect*> effList;

	bool isGameOver;

public:
	// Summary : �R���X�g���N�^
	GamePage(void);
	
	// Summary : �f�X�g���N�^
	~GamePage(void);
	
	// Summary : ����������
	void Init(void);
	
	// Summary : �X�V����
	void UpData(void);
	
	// Summary : �`�揈��
	void Draw(void);
	
	// Summary : ���\�[�X�ǂݍ���
	void LoadResource(void);

	void SetMinoPos(MINO* buf);

	// Summary : �w�肳�ꂽ�u���b�N�𐶐�
	// Param   : BLOCK::Type type = ��������u���b�N
	void MinoFactory(BLOCK::Type type);

	// Summary : �����_���ȃ~�m���擾
	// Returns : BLOCK::Type�^
	BLOCK::Type GetRandMino(void);
	
	// Summary : �X�g�b�N���X�V
	void PushMinoStock(void);
	
	// Summary : �~�m�̉�]
	// Param   : bool clockwise = true�F���v���,false:�����v���
	void SpinMino(bool clockwise);

	// Summary : �S�[�X�g�̐���
	void MakeGhost(void);

	void SetDrawHoldMinoPos(void);

	void SetDrawStockMinoPos(void);

	void EffectManager(void);

};


