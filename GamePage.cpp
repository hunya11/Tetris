#include "Root.h"


GamePage::GamePage(void)
{
	this->Init();
}


GamePage::~GamePage(void)
{
	for(int y=0;y<sizeof(block)/sizeof(block[y]);y++){
		for(int x=0;x<sizeof(block[y])/sizeof(block[y][x]);x++){
			if(block[y][x] != 0) delete block[y][x];
		}
	}

	delete rand;

}


void GamePage::Init(void){
	for(int y=0;y<sizeof(block)/sizeof(block[y]);y++){
		for(int x=0;x<sizeof(block[y])/sizeof(block[y][x]);x++){
			block[y][x] = new Block();
			block[y][x]->X(494 + (x * 30));
			block[y][x]->Y(-3 + (y * 30));
		}
	}

	for(int z=0;z<3;z++){
		for(int y=0;y<4;y++){
			for(int x=0;x<3;x++){
				stock[z][y][x] = new Block();
				stock[z][y][x]->X(494 - 30 * 5  + (x * 30));
				stock[z][y][x]->Y(-3 + 30 * 6 + (z * 30 * 5) + (y * 30));
			}
		}
	}

	for(int y=0;y<4;y++){
		for(int x=0;x<3;x++){
			hold[y][x] = new Block();
			hold[y][x]->X(494 - 30 * 5 + (x * 30));
			hold[y][x]->Y(-3 + 30 + (y * 30));
		}
	}

	for(int i=0;i<7;i++){
		dropBlock[i] = 0;
	}

	rand = new RandomNum();

	for(int i=0;i<4;i++){
		ghost[i].x = 0;
		ghost[i].y = 0;
		ghost[i].type = BLOCK::NONE;
	}

	for(int i=0;i<3;i++){
		minoNextStock[i] = GetRandMino();
	}
	//minoNextStock[0] = BLOCK::I;
	//minoNextStock[1] = BLOCK::I;

	MinoFactory(minoNextStock[0]);
	PushMinoStock();

	minoHold = BLOCK::NONE;

	isGrounding = false;
	isIdletime  = true;
	isHardDrop  = false;
	isCanMove   = true;
	isSpin		= false;
	isHold		= false;
	isAlreadyHold = false;

	OldIdleSeconds = 0;
	OldDropSeconds = 0;
	IdleMax = 1500;
	DropMax = 1000;


	//����ˁ[����
	//TCHAR bufOption[MAX_PATH];
	//GetPrivateProfileString("Option", "isOptionMinoDrop", "Err",bufOption, sizeof(bufOption) / sizeof(TCHAR), "./Data/System.ini");
	//if(string(bufOption) == "true"){
	//	isOptionMinoDrop = false;
	//}

	isOptionMinoDrop = true;
	isOptionDrawGMino = true;
	isOptionUseHardDrop = true;
	isOptionUseSpin = true;
	isOptionUseHold = true;
	isOptionShowNext = true;

	numScore = 0;

	isGameOver = false;

}


void GamePage::UpData(void){
	base::UpData();

	//if(key->CheckKeyPushed(KEY_INPUT_A) == true){
	//	stringstream ss;
	//	ss << setw(10) << /*setfill('0') <<*/ 100;
	//	effList.push_back(new Effect_FadeString(122,280,32,ss.str()));
	//}

	if(isGameOver == false){

		//�~�m�̈ʒu�i���j
		MINO buf[4];

		//��[�S������
		for(int i=0;i<4;i++){
			block[ghost[i].y][ghost[i].x]->Status(Block::STATUS::NONE);
			block[mino[i].y][mino[i].x]->Status(Block::STATUS::NONE);
			//�~�m�̉��ʒu�ݒ�
			buf[i] = mino[i];
		}

		isCanMove = true;
		isSpin		= false;
		isHold		= false;

		if(isGrounding == false){//�ڒn���Ă��Ȃ�
			for(int i=0;i<4;i++){
				//�����������Ƀu���b�N�������ԂȂ�
				if(mino[i].y == 19 || this->block[mino[i].y+1][mino[i].x]->Status()== Block::STATUS::FIX){
					isGrounding = true;//�ڒnON
					isIdletime  = true;//�A�C�h���^�C��ON
					OldIdleSeconds = this->localNowCount;//�A�C�h���J�n���ԑ���
					break;
				}
			}
		}else{//�ڒn���Ă���
			bool isUnGrounding = true;//�ڒn�����t���O
			for(int i=0;i<4;i++){
				//�ڒn���Ă���
				if(mino[i].y == 19 || this->block[mino[i].y+1][mino[i].x]->Status() == Block::STATUS::FIX) isUnGrounding = false;
			}
			if(isUnGrounding == true){//�ڒn���Ă��Ȃ�
				isGrounding = false;//�ڒnOFF
				IdleMax -= 300;//�A�C�h�����Ԃ̍ő�l�����炷
				OldDropSeconds = localNowCount;//���u���Ԃ̐ݒ�
			}
		}

		//�����A�C�h�����ԍő�l�𒴂�����
		if(this->localNowCount - this->OldIdleSeconds > this->IdleMax && isGrounding == true){
			isIdletime = false;//�A�C�h���^�C���I��
		}

		if(isHardDrop == true){//�n�[�h�h���b�v��ON�Ȃ�

			for(int i=0;i<4;i++){
				if(isGrounding == true){//�ڒn���Ă���
					isCanMove  = false;//�ړ��ł��Ȃ�
					isHardDrop = false;//�n�[�h�h���b�v�I��
					isIdletime = false;//�A�C�h���^�C���I��
					break;
				}
				//�~�m�����ɗ��Ƃ�
				buf[i].y++;
			}
		}else{//�n�[�h�h���b�v��OFF
			//��莞�ԕ��u
			if(this->localNowCount - this->OldDropSeconds > this->DropMax && isGrounding == false && isIdletime == true){
				for(int i=0;i<4;i++){
					if(isGrounding == true){//�ڒn���Ă���
						isCanMove = false;//�ړ��ł��Ȃ�
						break;
					}
					//���u���Ԃ̐ݒ�
					if(isCanMove == true) OldDropSeconds = localNowCount;
					//�~�m�����ɗ��Ƃ�
					if(isOptionMinoDrop == true) buf[i].y++;
				}
			}
	

			if(key->CheckKeyPushed(KEY_INPUT_UP) == true && isOptionUseHardDrop == true){//��L�[���������Ƃ�
				isHardDrop = true;//�n�[�h�h���b�vON
			}else if(key->CheckKeyPushed(KEY_INPUT_DOWN) == true){//���L�[���������Ƃ�
				for(int i=0;i<4;i++){
					if(isGrounding == true){//�ڒn���Ă���
						isCanMove = false;//�ړ��ł��Ȃ�
						break;
					}
					//���u���Ԃ̐ݒ�
					if(isCanMove == true) OldDropSeconds = localNowCount;
					//�~�m�����ɗ��Ƃ�
					buf[i].y++;
				}
			}else if(key->CheckKeyPushed(KEY_INPUT_RIGHT) == true){//�E�L�[���������Ƃ�
				for(int i=0;i<4;i++){
					//�E���ɕǂ��~�m������
					if(!(mino[i].x < sizeof(block[0])/sizeof(block[0][0])-1) || this->block[mino[i].y][mino[i].x+1]->Status() == Block::STATUS::FIX){
						isCanMove = false;//�ړ��s��
						break;
					}
					//�~�m���E�Ɉړ�
					buf[i].x++;
				}
			}else if(key->CheckKeyPushed(KEY_INPUT_LEFT) == true){//���L�[���������Ƃ�
				for(int i=0;i<4;i++){
					//�����ɕǂ��~�m������
					if(!(mino[i].x > 0) || this->block[mino[i].y][mino[i].x-1]->Status() == Block::STATUS::FIX){
						isCanMove = false;//�ړ��s��
						break;
					}
					//�~�m�����Ɉړ�
					buf[i].x--;
				}
			}

			//�z�[���h
			if(key->CheckKeyPushed(KEY_INPUT_TAB) == true && isOptionUseHold == true){	
				if(this->isAlreadyHold == false){//�܂��z�[���h�@�\���g���ĂȂ�
					this->isHold = true;
					this->isAlreadyHold = true;
					//�~�m�̉��
					for(int i=0;i<4;i++){
						this->block[mino[i].y][mino[i].x]->Status(Block::STATUS::NONE);
					}

					if(minoHold == BLOCK::NONE){//����
						//�V�����~�m�̐��Y
						minoHold = mino[0].type;
						MinoFactory(minoNextStock[0]);
						PushMinoStock();
					}else{
						//�z�[���h�ƌ���
						BLOCK::Type bufHold = minoHold;
						minoHold = mino[0].type;
						MinoFactory(bufHold);
					}

					//�e��t���O�Ȃǂ̏�����
					this->isGrounding = false;
					this->isHardDrop  = false;
					this->isIdletime  = true;
					this->IdleMax	  = 1500;
					this->OldDropSeconds = localNowCount;
				}
			}
	
			//��]
			if(key->CheckKeyPushed(KEY_INPUT_SPACE) == true && isOptionUseSpin == true){
				isSpin = true;
				//��]
				this->SpinMino(true);
			}
		}

		if(this->isCanMove == true && isSpin == false && isHold == false){
			//���݈ʒu�̔��f
			for(int i=0;i<4;i++){
				this->mino[i] = buf[i];
			}
		}

		if(isGrounding == true && isIdletime == false && isHold == false){

			//�~�m�̌Œ�
			for(int i=0;i<4;i++){
				this->block[mino[i].y][mino[i].x]->Status(Block::STATUS::FIX);
			}

			//����

			int delLine = 0;
			for(int y=0;y<sizeof(block)/sizeof(block[y]);y++){
				if(this->block[y][0]->Status() == Block::STATUS::FIX
					&& this->block[y][1]->Status() == Block::STATUS::FIX
					&& this->block[y][2]->Status() == Block::STATUS::FIX
					&& this->block[y][3]->Status() == Block::STATUS::FIX
					&& this->block[y][4]->Status() == Block::STATUS::FIX
					&& this->block[y][5]->Status() == Block::STATUS::FIX
					&& this->block[y][6]->Status() == Block::STATUS::FIX
					&& this->block[y][7]->Status() == Block::STATUS::FIX
					&& this->block[y][8]->Status() == Block::STATUS::FIX
					&& this->block[y][9]->Status() == Block::STATUS::FIX){

						delLine++;

						for(int x=0;x<sizeof(block[y])/sizeof(block[y][x]);x++){
							//�G�t�F�N�g
							base::RunEffect(new Effect_DelBlock(this->block[y][x]->X() + this->block[y][x]->SizeX() / 2, this->block[y][x]->Y() + this->block[y][x]->SizeY() / 2,this->block[y][x]->Texture()));
						}

						//�Ȃ�񂾂炯��
						for(int y2 = y; y2>0;y2--){
							for(int x=0;x<sizeof(block[y])/sizeof(block[y][x]);x++){
								this->block[y2][x]->BlockType(this->block[y2-1][x]->BlockType());
								this->block[y2][x]->Status(this->block[y2-1][x]->Status());
							}
						}

						for(int x=0;x<sizeof(block[y])/sizeof(block[y][x]);x++){
							this->block[0][x]->Status(Block::STATUS::NONE);
						}

				}
			}
		
			if(delLine != 0){
				stringstream ss;
				switch(delLine){
				case 1:
					numScore += SCORE_POINT::LINE1;
					ss << setw(10) << SCORE_POINT::LINE1;
					break;
				case 2:
					numScore += SCORE_POINT::LINE2;
					ss << setw(10) << SCORE_POINT::LINE2;
					break;
				case 3:
					numScore += SCORE_POINT::LINE3;
					ss << setw(10) << SCORE_POINT::LINE3;
					break;
				case 4:
					numScore += SCORE_POINT::LINE4;
					ss << setw(10) << SCORE_POINT::LINE4;
					break;
				}
				base::RunEffect(new Effect_FadeString(122,280,32,ss.str()));
			}

			//�V�����~�m�̐��Y
			MinoFactory(minoNextStock[0]);
			PushMinoStock();

			//�e��t���O�Ȃǂ̏�����
			this->isGrounding = false;
			this->isHardDrop  = false;
			this->isIdletime  = true;
			this->isAlreadyHold = false;
			this->IdleMax	  = 1500;
			this->OldDropSeconds = localNowCount;
		}

		if(isOptionDrawGMino == true){
			//�S�[�X�g�̍쐬
			this->MakeGhost();
		}

		//�~�m�̍X�V
		for(int i=0;i<4;i++){
			if(isOptionDrawGMino == true){
				block[ghost[i].y][ghost[i].x]->Status(Block::STATUS::GHOST);
				block[ghost[i].y][ghost[i].x]->BlockType(ghost[i].type);
			}

			block[mino[i].y][mino[i].x]->Status(Block::STATUS::MOVE);
			block[mino[i].y][mino[i].x]->BlockType(mino[i].type);
		}

		//�u���b�N�̍X�V����
		for(int y=0;y<sizeof(block)/sizeof(block[0]);y++){
			for(int x=0;x<sizeof(block[0])/sizeof(block[0][0]);x++){
				block[y][x]->UpData();
			}
		}

		//�X�g�b�N�̍X�V����
		this->SetDrawStockMinoPos();
		for(int z=0;z<3;z++){
			for(int y=0;y<4;y++){
				for(int x=0;x<3;x++){
					stock[z][y][x]->UpData();
				}
			}
		}

		//�z�[���h�̍X�V����
		SetDrawHoldMinoPos();
		for(int y=0;y<4;y++){
			for(int x=0;x<3;x++){
				hold[y][x]->UpData();
			}
		}

	}

	



	//�G�X�P�[�v�L�[�ŃQ�[���I��
	if(key->CheckKeyPushed(KEY_INPUT_ESCAPE) == true){
		NowPage(FRAME_PAGE::TITLE);
	}
}


void GamePage::Draw(void){

	DrawFormatString( 0, 0, GetColor( 255 , 255 , 255 ), "GamePage:%d",localNowCount);

	//for(int i=0;i<3;i++){
	//	DrawFormatString( 0, 17+i*17, GetColor( 255 , 255 , 255 ), "Next:%d",minoNextStock[i]);
	//}
	//
	//DrawFormatString( 100, 17, GetColor( 255 , 255 , 255 ), "Hold:%d",minoHold);
	
	//�u���b�N�`��
	for(int y=0;y<sizeof(block)/sizeof(block[y]);y++){
		for(int x=0;x<sizeof(block[y])/sizeof(block[y][x]);x++){
			block[y][x]->Draw();
		}
	}
	
	//Next�\��
	DrawFormatString( 370, 155, GetColor( 255 , 255 , 255 ), "NEXT");
	for(int z=0;z<3;z++){
		for(int y=0;y<4;y++){
			for(int x=0;x<3;x++){
				/*if(stock[z][y][x]->BlockType() != BLOCK::NONE) */stock[z][y][x]->Draw();
			}
		}
	}
	

	//�z�[���h�\��
	DrawFormatString( 370, 5, GetColor( 255 , 255 , 255 ), "HOLD");
	for(int y=0;y<4;y++){
		for(int x=0;x<3;x++){
			/*if(hold[y][x]->BlockType() != BLOCK::NONE) */hold[y][x]->Draw();
		}
	}

	//�X�R�A�\��
	SetFontSize(32);
	DrawFormatString(20,300,GetColor( 255 , 255 , 255 ),"Score:%010d",numScore);
	SetFontSize(16);

	//�Q�[���I�[�o�[���
	if(isGameOver == true){
		SetFontSize(32);
		DrawFormatString(20,100,GetColor( 255 , 255 , 255 ),"GameOver!");
		SetFontSize(16);
	}

	base::Draw();
}


void GamePage::LoadResource(void){
}


void GamePage::SetMinoPos(MINO* buf){
	switch(buf[0].type){
	case BLOCK::I:
		buf[0].x = 1;
		buf[0].y = 0;
		buf[1].x = 1;
		buf[1].y = 1;
		buf[2].x = 1;
		buf[2].y = 2;
		buf[3].x = 1;
		buf[3].y = 3;
		break;
	case BLOCK::O:
		buf[0].x = 0;
		buf[0].y = 0;
		buf[1].x = 1;
		buf[1].y = 0;
		buf[2].x = 0;
		buf[2].y = 1;
		buf[3].x = 1;
		buf[3].y = 1;
		break;
	case BLOCK::S:
		buf[0].x = 0;
		buf[0].y = 1;
		buf[1].x = 1;
		buf[1].y = 1;
		buf[2].x = 1;
		buf[2].y = 0;
		buf[3].x = 2;
		buf[3].y = 0;
		break;
	case BLOCK::Z:
		buf[0].x = 0;
		buf[0].y = 0;
		buf[1].x = 1;
		buf[1].y = 0;
		buf[2].x = 1;
		buf[2].y = 1;
		buf[3].x = 2;
		buf[3].y = 1;
		break;
	case BLOCK::J:
		buf[0].x = 0;
		buf[0].y = 0;
		buf[1].x = 0;
		buf[1].y = 1;
		buf[2].x = 1;
		buf[2].y = 1;
		buf[3].x = 2;
		buf[3].y = 1;
		break;
	case BLOCK::L:
		buf[0].x = 0;
		buf[0].y = 1;
		buf[1].x = 1;
		buf[1].y = 1;
		buf[2].x = 2;
		buf[2].y = 1;
		buf[3].x = 2;
		buf[3].y = 0;
		break;
	case BLOCK::T:
		buf[0].x = 1;
		buf[0].y = 0;
		buf[1].x = 0;
		buf[1].y = 1;
		buf[2].x = 1;
		buf[2].y = 1;
		buf[3].x = 2;
		buf[3].y = 1;
		break;
	}
}


void GamePage::MinoFactory(BLOCK::Type type){
	int numAddPosX = 4;

	MINO buf[4];
	for(int i=0;i<4;i++){
		buf[i].x = 0;
		buf[i].y = 0;
		buf[i].type = type;
	}

	this->SetMinoPos(buf);
	
	for(int i=0;i<4;i++){
		buf[i].x += numAddPosX;
		this->mino[i] = buf[i];
		if(block[this->mino[i].y][this->mino[i].x]->Status() != Block::STATUS::NONE) isGameOver = true;
		block[this->mino[i].y][this->mino[i].x]->BlockType(this->mino[i].type);
		block[this->mino[i].y][this->mino[i].x]->Status(Block::STATUS::MOVE);
	}


	this->MakeGhost();

}


BLOCK::Type GamePage::GetRandMino(void){
	list<int> ex;
	for(int i=0;i<7;i++){
		if(dropBlock[i] != 0) ex.push_back(i);
	}
	if(ex.size() != 7){
		int num = 0;
		try{
			num = (rand->GetRand(6,ex));
		}catch(int ex){
			num = (rand->GetRand(6));
		}
		dropBlock[num]++;
		return (BLOCK::Type)num;
	}
	else return (BLOCK::Type)(rand->GetRand(6))	;
}


void GamePage::PushMinoStock(void){
	for(int i=0;i<3-1;i++){
		minoNextStock[i] = minoNextStock[i+1]; 
	}
	minoNextStock[2] = GetRandMino();
}


void GamePage::SpinMino(bool clockwise){

	if(mino[0].type != BLOCK::I){

		int swapA[3][3];
		int swapB[3][3];
		int minX;
		int minY;
		MINO buf[4];

		for(int y=0;y<3;y++){
			for(int x=0;x<3;x++){
				swapA[y][x] = 0;
				swapB[y][x] = 0;
			}
		}
		minX = mino[0].x;
		minY = mino[0].y;
		for(int i=0;i<4;i++){
			buf[i] = mino[i];
			if(minX > buf[i].x) minX = buf[i].x;
			if(minY > buf[i].y) minY = buf[i].y;
		}
		for(int i=0;i<4;i++){
			swapA[buf[i].y - minY][buf[i].x - minX] = 1;
		}

		swapB[0][2] = swapA[0][0];
		swapB[1][2] = swapA[0][1];
		swapB[2][2] = swapA[0][2];
		swapB[0][1] = swapA[1][0];
		swapB[1][1] = swapA[1][1];
		swapB[2][1] = swapA[1][2];
		swapB[0][0] = swapA[2][0];
		swapB[1][0] = swapA[2][1];
		swapB[2][0] = swapA[2][2];

		int num = 0;
		for(int y=0;y<3;y++){
			for(int x=0;x<3;x++){
				if(swapB[y][x] == 1){
					buf[num].x = x + minX;
					buf[num].y = y + minY;
					num++;
				}
			}
		}

		bool isErr = false;
		for(int i = 0; i < 4; i++) {
			if(buf[i].x < 0 || buf[i].x > 9) isErr = true;
			if(buf[i].y < 0 || buf[i].y > 19) isErr = true;
			if(isErr == false && block[buf[i].y][buf[i].x]->Status() == Block::STATUS::FIX) isErr = true;
		}

		if(isErr == false){
			for(int i=0;i<4;i++){
				mino[i] = buf[i];
			}
		}

	}else{
		int swapA[4][4];
		int swapB[4][4];
		int minX;
		int minY;
		MINO buf[4];

		for(int y=0;y<4;y++){
			for(int x=0;x<4;x++){
				swapA[y][x] = 0;
				swapB[y][x] = 0;
			}
		}
		minX = mino[0].x;
		minY = mino[0].y;
		for(int i=0;i<4;i++){
			buf[i] = mino[i];
			if(minX > buf[i].x) minX = buf[i].x;
			if(minY > buf[i].y) minY = buf[i].y;
		}
		for(int i=0;i<4;i++){
			swapA[buf[i].y - minY][buf[i].x - minX] = 1;
		}

		swapB[0][3] = swapA[0][0];
		swapB[1][3] = swapA[0][1];
		swapB[2][3] = swapA[0][2];
		swapB[3][3] = swapA[0][3];
		swapB[0][2] = swapA[1][0];
		swapB[1][2] = swapA[1][1];
		swapB[2][2] = swapA[1][2];
		swapB[3][2] = swapA[1][3];
		swapB[0][1] = swapA[2][0];
		swapB[1][1] = swapA[2][1];
		swapB[2][1] = swapA[2][2];
		swapB[3][1] = swapA[2][3];
		swapB[0][0] = swapA[3][0];
		swapB[1][0] = swapA[3][1];
		swapB[2][0] = swapA[3][2];
		swapB[3][0] = swapA[3][3];

		int num = 0;
		for(int y=0;y<4;y++){
			for(int x=0;x<4;x++){
				if(swapB[y][x] == 1){
					buf[num].x = x + minX;
					buf[num].y = y + minY;
					num++;
				}
			}
		}

		bool isErr = false;
		for(int i = 0; i < 4; i++) {
			if(buf[i].x < 0 || buf[i].x > 9) isErr = true;
			if(buf[i].y < 0 || buf[i].y > 19) isErr = true;
			if(isErr == false && block[buf[i].y][buf[i].x]->Status() == Block::STATUS::FIX) isErr = true;
		}

		if(isErr == false){
			for(int i=0;i<4;i++){
				mino[i] = buf[i];
			}
		}
	}

}


void GamePage::MakeGhost(void){
	int num = 20;
	for(int i=0;i<4;i++){
		int num2 = 0;
		while(mino[i].y + num2 != 20 && this->block[mino[i].y + num2][mino[i].x]->Status() != Block::STATUS::FIX){
			num2++;
		}
		if(num2 < num) num = num2;
	}
	num--;
	for(int i=0;i<4;i++){
		ghost[i].x = mino[i].x;
		ghost[i].y = mino[i].y + num;
		ghost[i].type = mino[i].type;
	}
}


void GamePage::SetDrawHoldMinoPos(void){
	if(this->minoHold == BLOCK::NONE) return;

	MINO buf[4];
	for(int i=0;i<4;i++){
		buf[i].x = 0;
		buf[i].y = 0;
		buf[i].type = this->minoHold;
	}
	this->SetMinoPos(buf);

	for(int y=0;y<4;y++){
		for(int x=0;x<3;x++){
			hold[y][x]->BlockType(BLOCK::NONE);
			hold[y][x]->Status(Block::STATUS::NONE);
		}
	}

	for(int i=0;i<4;i++){
		hold[buf[i].y][buf[i].x]->BlockType(buf[i].type);
		hold[buf[i].y][buf[i].x]->Status(Block::STATUS::FIX);
	}

}


void GamePage::SetDrawStockMinoPos(void){

	for(int z=0;z<3;z++){
		MINO buf[4];
		for(int i=0;i<4;i++){
			buf[i].x = 0;
			buf[i].y = 0;
			buf[i].type = this->minoNextStock[z];
		}
		this->SetMinoPos(buf);

		for(int y=0;y<4;y++){
			for(int x=0;x<3;x++){
				stock[z][y][x]->BlockType(BLOCK::NONE);
				stock[z][y][x]->Status(Block::STATUS::NONE);
			}
		}

		if(isOptionShowNext == true){
			for(int i=0;i<4;i++){
				stock[z][buf[i].y][buf[i].x]->BlockType(buf[i].type);
				stock[z][buf[i].y][buf[i].x]->Status(Block::STATUS::FIX);
			}
		}
	}
}

