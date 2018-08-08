#pragma once

#include "D2Item.h"
#include "DlgPropertyList.h"

#include <memory>

// CDlgFoundry 对话框

class CDlgFoundry : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgFoundry)

	CD2Item & m_stItem;
	std::pair<CPropertyList, BOOL> m_aProps[7];	//propList + setProps[5] + runeWord

	//UI
	CString m_sText[22];
	int m_iSelectedPropItem = -1;	//当前选中的属性列表项

public:
	CDlgFoundry(CD2Item & item, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgFoundry();
	void InitUI();
	void ReadItem();
	void ReadItemEar(const CEar & ear);
	void ReadItemInfo(CItemInfo & info);
	void ReadItemGold(const CGoldQuantity & gold);
	void ReadExtItemInfo(const CExtItemInfo & extInfo);
	void ReadTypeSpecificInfo(CTypeSpecificInfo & spec);
	void ReadItemLongName(const CLongName & longName);
	void UpdatePropList();
	void SelectPropItem(int id, int value);

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Foundry };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
private:
	CComboBox m_cbClass;
	CComboBox m_cbQuality;
	CComboBox m_cbMonster;
	CComboBox m_cbRareCraftedName[2];
	CComboBox m_cbSubType;
	CComboBox m_cbPrefix[3];
	CComboBox m_cbSuffix[3];
	CComboBox m_cbSetName;
	CComboBox m_cbUniqueName;
	CEdit m_edLevel;
	BOOL m_bUnidentified;
	BOOL m_bEthereal;
	CButton m_chIndestructible;
	CEdit m_edMaxDurability;
	CEdit m_edDurability;
	CEdit m_edQuantity;
	CEdit m_edOwner;
	CEdit m_edSockets;
	CString m_sExtSockets;
	CEdit m_edDefence;
	CTabCtrl m_tabPropList;
	CListCtrl m_lstProperty;
	CEdit m_edParam[3];
	CString m_sTip[3];
public:
	afx_msg void OnBnClickedCheckIndestructible();
	afx_msg void OnCbnSelchangeComboQuality();
	afx_msg void OnTcnSelchangeTabProperty(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
};
