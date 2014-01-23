#pragma once
class GamePage : public Page
{
private:

	// Summary : �e�N���X
	typedef Page base;

	// Summary : ���_
	struct SCORE_POINT{
		enum Point{
			LINE1 = 100,
			LINE2 = 250,
			LINE3 = 625,
			LINE4 = 1500,
		};
	};

	// Summary : �~�m
	struct MINO{
		// Summary : x���W
		int x;
		// Summary : y���W
		int y;
		// Summary : �`
		Block::FORM::Type type;
	};


	// Summary : �u���b�N
	Block* block[20][10];

	// Summary : �z�[���h
	Block* hold[4][3];

	// Summary : �X�g�b�N
	Block* stock[3][4][3];
	
	// Summary : ���삷��~�m
	MINO mino[4];

	// Summary : ���삷��~�m�̃S�[�X�g
	MINO ghost[4];

	// Summary : ���ԑ҂��~�m�̌`
	Block::FORM::Type minoNextStock[3];
	
	// Summary : �z�[���h�����~�m�̌`
	Block::FORM::Type minoHold;

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
	
	int NowIdleSeconds;

	// Summary : �A�C�h���^�C���̍ő厞��
	int IdleMax;
	
	// Summary : �����ҋ@�̍ő厞��
	int DropMax;

	// Summary : ���Ƃ����u���b�N�̕��z
	int dropBlock[7];

	// Summary : �X�R�A
	int numScore;
	
	// Summary :�@���������C���̐�
	int numDelLine;

	// Summary :�@�Q�[�����x��
	int numGameLevel;

	// Summary : �Q�[���I�[�o�[���ǂ���
	bool isGameOver;
	


	//�I�v�V����
	// Summary : �~�m�����Ԃŗ������邩
	bool isOptionMinoDrop;

	// Summary : �S�[�X�g��\�����邩
	bool isOptionDrawGMino;

	// Summary : �n�[�h�h���b�v���g���邩
	bool isOptionUseHardDrop;

	// Summary : �~�m����]�ł��邩
	bool isOptionUseSpin;

	// Summary : �z�[���h���g�p�ł��邩
	bool isOptionUseHold;

	// Summary : �l�N�X�g�u���b�N���m�F�ł��邩
	bool isOptionShowNext;

	int numTime_m;
	int numTime_s;
	int numTime_ms;


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
	// Param   : Block::FORM::Type type = ��������u���b�N
	void MinoFactory(Block::FORM::Type type);

	// Summary : �����_���ȃ~�m���擾
	// Returns : Block::FORM::Type�^
	Block::FORM::Type GetRandMino(void);
	
	// Summary : �X�g�b�N���X�V
	void PushMinoStock(void);
	
	// Summary : �~�m�̉�]
	// Param   : bool clockwise = true�F���v���,false:�����v���
	void SpinMino(bool clockwise);

	// Summary : �S�[�X�g�̐���
	void MakeGhost(void);

	void SetDrawHoldMinoPos(void);

	void SetDrawStockMinoPos(void);


};


