#pragma once
class Page : public DrawableComponent
{
private:
	// Summary : �e�N���X
	typedef DrawableComponent base;

	// Summary : �y�[�W���N�������Ƃ��̎���
	int startNowCount;
protected:
	// Summary : �L�[���͊Ǘ�
	static KeyPushed* key;
	
	// Summary : ���삷��y�[�W
	static FRAME_PAGE::Type nowPage;
	
	// Summary : �y�[�W���N�����Ă���̎���
	int localNowCount;
public:
	// Summary : �R���X�g���N�^
	Page(void);
	
	// Summary : �f�X�g���N�^
	virtual ~Page(void) = 0;

	// Summary : �`�揈��
	virtual void UpData(void);

	// Summary : ���\�[�X�ǂݍ���
	virtual void LoadResource(void) = 0;

	/*�v���p�e�B*/
	void static NowPage(FRAME_PAGE::Type fp);
	FRAME_PAGE::Type static NowPage(void);

};

