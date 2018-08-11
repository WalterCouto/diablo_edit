#pragma once

#include "D2Item.h"

#include <memory>

int intOf(const CEdit & edit);

// CDlgFoundry 对话框

class CDlgFoundry : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgFoundry)

	CD2Item & m_stItem;
	std::pair<CPropertyList, BOOL> m_aProps[7];	//propList + setProps[5] + runeWord

	//UI
	CString m_sText[19];
	int m_iSelectedPropItem = -1;	//当前选中的属性列表项

public:
	CDlgFoundry(CD2Item & item, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgFoundry();
private:
	//读取物品数据，展示UI
	void InitUI();
	void ReadItem();
	void ReadItemEar(const CEar & ear);
	void ReadItemInfo(CItemInfo & info);
	void ReadItemGold(const CGoldQuantity & gold);
	void ReadExtItemInfo(const CExtItemInfo & extInfo);
	void ReadTypeSpecificInfo(CTypeSpecificInfo & spec);
	void ReadItemLongName(const CLongName & longName);
	//收集UI数据存入物品
	BOOL GatherData();
	void WriteItem(CD2Item & item);
	void WriteItemEar(CEar & ear);
	void WriteItemInfo(CItemInfo & info, BOOL bSimple, BOOL & bPersonalized, const CItemMetaData & meta, BOOL & bSocketed, BOOL bRuneWord);
	void WriteItemGold(CGoldQuantity & gold);
	void WriteExtItemInfo(CExtItemInfo & extInfo, BOOL & bPersonalized, const CItemMetaData & meta);
	void WriteTypeSpecificInfo(CTypeSpecificInfo & spec, const CItemMetaData & meta, BOOL & bSocketed, BOOL bIsSet, BOOL bRuneWord);
	void WriteItemLongName(CLongName & longName);
	void validate(bool expr, int index);
	void setPreSuffix(BOOL & exist, MayExist<WORD> & index, const CComboBox & cb, int max, int msg);

	void UpdatePropList();	//根据属性TAB的选择，更新属性列表
	BOOL ChangePropItemSelection(LPNMLISTVIEW pNMLV);	//检查属性列表选中项的变化，更新参数控件
	BOOL ChangePropItemChecked(LPNMLISTVIEW pNMLV);		//检查属性列表check项的变化，增加/删除属性，更新参数控件
	void SetupPropParameters(int id, int value);		//根据属性id和值，更新参数控件

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
	CEdit m_edParam[4];
	CString m_sTip[4];
public:
	void OnOK();
	afx_msg void OnBnClickedCheckIndestructible();
	afx_msg void OnCbnSelchangeComboQuality();
	afx_msg void OnTcnSelchangeTabProperty(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeParam();
};
