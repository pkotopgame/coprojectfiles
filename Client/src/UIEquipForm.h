#pragma once
#include "UIGlobalVar.h"
#include "NetProtocol.h"
#include "SkillRecord.h"
#include "UIGuiData.h"

class CCharacter;
class CSkillStateRecord;
struct stNetSkillBag;

namespace GUI
{
class CItemCommand;

// ���ܣ����ߣ���ݷ�ʽ��װ��
class CEquipMgr : public CUIInterface
{
public:

	int				GetIMP(){return lIMP;}

	void			SynSkillBag(DWORD dwCharID, stNetSkillBag *pSSkillBag);

    void            UpdataEquip( const stNetChangeChaPart& SPart, CCharacter* pCha );
    void            UpdataEquipSpy( const stNetChangeChaPart& SPart, CCharacter* pCha );
    void            UpdataEquipData( const stNetChangeChaPart& SPart, CCharacter* pCha ) const;

    void            UpdateShortCut( stNetShortCut& stShortCut );		// ���¿����
	void			DelFastCommand( CCommandObj* pObj );				// ɾ����ǰ�����
    bool            ExecFastKey( int key );
	void			FastChange(int nIndex, short sGridID, char chType,bool update = false);

	void            CloseAllForm();		// �رմ���

	// ���������������Ƚ�,�����������ͬ�Ŀ����,�����������Э����¿����,���ظ��µĸ���
	// ���ڵ����ڵ���������ʱ
	int				RefreshServerShortCut();							

	CGoodsGrid* GetGoodsGrid() { return grdItem; }	// �������������
	CForm* GetItemForm() { return frmInv; }   // �������߱�

	CForm* stateDrags;

	// ��װ����ж�ص��ߵ�������
	void			UnfixToGrid( CCommandObj* pItem, int nGridID, int nLink );

	CSkillRecord*	FindSkill( int nID );

	CItemCommand*	GetEquipItem( unsigned int nLink ) const;

	bool			IsEquipCom( COneCommand* pCom ) const;

	void			SetIsLock(bool bLock) const;
	bool			GetIsLock() const;
	
	void 			UpdateIMP(int imp) const;

	// ��õ����ڵ�ǰ�������ܵĸ���
	int				GetItemCount(int nID);

	static CGuiPic*		GetChargePic( unsigned int n );

	void ShowSellPrompt() const;
    static void		evtThrowItemEvent(CGuiData *pSender,int id,bool& isThrow);					// �ӵ��������ӳ�����
    static void		evtSwapItemEvent(CGuiData *pSender,int nFirst, int nSecond, bool& isSwap); // �������н�������

protected:
	virtual bool Init();
    virtual void End();
	virtual void LoadingCall();
	virtual void FrameMove(DWORD dwTime);
	virtual void SwitchMap();
private:
	enum eDirectType
	{
		LEFT = -1, RIGHT = 1,
	};
	
	static void _UnequipPart(CGuiData *pSender, int x, int y, DWORD key);
	void RotateSpy(eDirectType enumDirect = LEFT);
	void RotateCha(eDirectType enumDirect = LEFT);

    CSkillList*		GetSkillList( char nType );
	void			RefreshUpgrade();
	void			RefreshSkillJob( int nJob );
	void			RenderSpy(int x,int y);
	void			RenderCha(int x,int y);
	static void 			RenderModel(int x, int y, CCharacter* original, CCharacter* model, int rotation, bool refresh = false);

	static bool			_GetThrowPos( int& x, int& y );
	static void ThrowSelectedItems(CGoodsGrid* grid);
	static void LockSelectedItems(CGoodsGrid* grid);
	static void DeleteSelectedItems(CGoodsGrid* grid);
public:
	bool			_GetCommandShortCutType( CCommandObj* pItem, char& chType, short& sGridID );
private:
	static void		_EqSpyRenderEvent(C3DCompent *pSender, int x, int y);
	static void		_ChaRenderEvent(C3DCompent *pSender, int x, int y);
	
	static void		_evtSkillFormShow(CGuiData *pSender);
	static void		_evtEquipFormShow(CGuiData *pSender);
	static void		_evtEquipFormClose( CForm *pForm, bool& IsClose );
	
	static void		_evtSpyFormClose( CForm *pForm, bool& IsClose );
	static void		_evtSpyFormShow(CGuiData *pSender);

	static void		_evtSkillUpgrade(CSkillList *pSender, CSkillCommand* pSkill);
    static void		_evtFastChange(CGuiData *pSender, CCommandObj* pItem, bool& isAccept);		// ����������仯
	static void		_evtEquipEvent(CGuiData *pSender, CCommandObj* pItem, bool& isAccept);		// �ӵ�������װ����װ����
	static void		_evtThrowEquipEvent(CGuiData *pSender, CCommandObj* pItem, bool& isThrow);  // ��װ�����ӳ�װ��

	static void		_evtButtonClickEvent( CGuiData *pSender, int x, int y, DWORD key);
	static void		_evtRMouseGridEvent(CGuiData *pSender,CCommandObj* pItem,int nGridID);

	bool			_UpdataEquip( SItemGrid& Item, int nLink );
	bool			_UpdataEquipSpy( SItemGrid& Item, int nLink ) const;
    void			_ActiveFast( int num );         // ����ڼ���

	static void		_evtItemFormMouseEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey);

	// ���� MSGBOX ȷ��
	static void		_CheckLockMouseEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey);

	static void _RotateChaLeft(CGuiData *sender, int x, int y, DWORD key );
	static void _RotateChaRight(CGuiData *sender, int x, int y, DWORD key );
	static void _RotateChaLeftContinue(CGuiData *sender );
	static void _RotateChaRightContinue(CGuiData *sender );

	static void _RotateSpyLeft(CGuiData *sender, int x, int y, DWORD key );
	static void _RotateSpyRight(CGuiData *sender, int x, int y, DWORD key );
	static void _RotateSpyLeftContinue(CGuiData *sender );
	static void _RotateSpyRightContinue(CGuiData *sender );
	static void _showSortOptions(CGuiData* pSender);
	//static void _ClickOpenApparel(CGuiData *pSender, int x, int y, DWORD key );
	static void _ClickTempBag(CGuiData* pSender, int x, int y, DWORD key);
	static void _OnDragStates(CGuiData* pSender, int x, int y, DWORD key);

	static void _ClickGoldStore(CGuiData* pSender, int x, int y, DWORD key);
	static void _evtGoldStoreEvent(CCompent* pSender, int nMsgType, int x, int y, DWORD dwKey);
	static void _ClickSortInv(CGuiData* pSender, int x, int y, DWORD key);
	//chest preview function @mothannakh
	CForm* formChestPreview{ nullptr };
	CLabelEx* LabelChestName{ nullptr };
	CGoodsGrid* chestPreview{ nullptr };
	void InitShowChestItems(int chestItems = 0) const;
	void SetupChestItems();
	struct chestItems {
		int itemID{ 0 };
		int itemQty{ 0 };
		float itemChance{ 0.0f };
		chestItems(const int itemID, const int itemQty, const float itemChance) : itemID(itemID), itemQty(itemQty), itemChance(itemChance) {}
		~chestItems() = default;
		bool operator==(const chestItems& rhs) const {
			return itemID == rhs.itemID;
		}
		chestItems(const chestItems& copy) = default; // corrected copy constructor
		auto operator<=>(const chestItems&) const = default;
		chestItems(chestItems&& move) = default;				// Move constructor
		chestItems& operator=(chestItems&& moveas) = default; // Move assignment
		chestItems& operator=(const chestItems& rhs) = default;
	};
	class chestItemsHasher {
	public:
		size_t operator()(const int& key) const {
			return std::hash<int>()(key);
		}
	};

	struct vectorHasher {
		template <typename T>
		std::size_t operator()(const std::vector<T>& vec) const {
			std::size_t seed = vec.size();
			for (const auto& elem : vec) {
				seed ^= std::hash<T>()(elem) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			}
			return seed;
		}
	};

	std::unordered_map<int, std::vector<chestItems>, chestItemsHasher> TotalChestItemsList{};


private:
	static int				lIMP;
	CForm*			frmSkill;

    CLabel*         labPoint;                   // ʣ�༼�ܵ���
    CLabel*         labPointLife;               // ʣ������ܵ���
    CSkillList*     lstFightSkill;              // ս��������
    CSkillList*     lstLifeSkill;               // �������
    CSkillList*     lstSailSkill;               // ����������

	
	CTextButton* btnOpenTempBag;
	CTextButton* btnSortPrice;
	CTextButton* btnSortAlpha;
	CTextButton* btnSortType;
	CTextButton* btnSortID;
	
	
	CCheckBox* chkLinkEqForm;
	
	CForm*			frmItemSpy;					// ���߱�
	CGoodsGrid*     grdItem;					// ������
	COneCommand*    cnmEquip[enumEQUIP_NUM];    // װ����
	COneCommand*    cnmEquipSpy[enumEQUIP_NUM];    // װ����
    stNetChangeChaPart    stEquip;
    stNetChangeChaPart    stEquipSpy;
    stNetShortCut         _stShortCut;

    int				_nFastCur;					// �����Ŀǰ�ڵڼ�λ
    CFastCommand**  _pFastCommands;
	CLabel*			_pActiveFastLabel;			// ���ڼ���������ҳ��

	CLabel*			lblGold;					// ��Ǯ
	CImage*			imgItem4;					// ����ǰ4���ͼƬ

	CImage*			imgLock;
	CImage*			imgUnLock;
	CCharacter* 	eqSpyTarget;
	int 					eqSpyTargetRotate;
	int 					chaModelRotate;
	
	CCharacter* 	chaModel;
	CCharacter* 	spyModel;
	
public:
	bool	refreshChaModel;
	bool	refreshSpyModel;


private:
	struct stThrow
	{
		stThrow() : nX(0), nY(0), nGridID(0), pSelf(0) {}

		int				nX, nY;
		int				nGridID;
		CCharacter* pSelf;
	};
	stThrow		_sThrow;
	static void _evtThrowDialogEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey);
	static void _evtThrowBoatDialogEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey);
	static void		_SendThrowData( const stThrow& sthrow, int nThrowNum=1 );

	struct stUnfix
	{
		stUnfix() : nLink(0), nGridID(0), nX(0), nY(0), pItem(nullptr) {}
		void	Reset()	{ nGridID=-1; nLink=-1;	pItem= nullptr;}

		int		nLink;
		int		nGridID;
		int		nX, nY;
		CCommandObj* pItem;
	};
	stUnfix		_sUnfix;

	static void _evtUnfixDialogEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey);
	static void		_SendUnfixData( const stUnfix& unfix, int nUnfixNum=1 );
	static void		_StartUnfix( stUnfix& unfix );


	static void _evtDeleteItemYesNoEvent(CCompent* pSender, int nMsgType, int x, int y, DWORD dwKey);
	static void _evtLockItemYesNoEvent(CCompent* pSender, int nMsgType, int x, int y, DWORD dwKey);
	int			_nLostGridID;
	int rightClickItemIndex{};
	CMenu* rightClickItemMenu{};

	typedef	std::vector<CSkillRecord*>	vskill;
	vskill		_skills;

	typedef std::vector<int>	ints;
	vskill		_cancels;			// �ɱ�����ļ���״̬

	typedef std::vector<CSkillStateRecord*>  states;
	states		_charges;			// ���ļ���״̬

	static CGuiPic	_imgCharges[enumEQUIP_NUM];

	struct SSplitItem
	{
		static void		_evtSplitItemEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey);	// ��ֵ��߻ص�
		int			nFirst;
		int			nSecond;
		CCharacter*	pSelf;
	};
	static SSplitItem	SSplit;

public:	// ����������
	void	ShowRepairMsg( const char* pItemName, long lMoney );
	void    SetIsShow(bool bShow);

private:
	static void		_evtRepairEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey);
public:
	CForm*			frmInv;	
};

inline CSkillList* CEquipMgr::GetSkillList( char nType )	
{ 
	switch( nType )
	{
	case enumSKILL_SAIL: return lstSailSkill;
	case enumSKILL_FIGHT: return lstFightSkill;
	default: return lstLifeSkill;
	}
}	

}

