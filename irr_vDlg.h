// irr_vDlg.h : header file
//
/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Irregular verbs.
	This file contains the definition of main program.
	
    Irregular verbs is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Irregular verbs is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Irregular verbs; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  
*/

#if !defined(AFX_IRR_VDLG_H__06D6FD4A_C433_472B_B11B_46BD744F9058__INCLUDED_)
#define AFX_IRR_VDLG_H__06D6FD4A_C433_472B_B11B_46BD744F9058__INCLUDED_
#include<string>
using namespace std ;
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CIrr_vDlg dialog

class CIrr_vDlg : public CDialog
{
// Construction
public:
	CIrr_vDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CIrr_vDlg)
	enum { IDD = IDD_IRR_V_DIALOG };
	CString	m_file;
	CString	m_participle;
	CString	m_simple;
	CString	m_infinitive;
	CString	m_participleOK;
	CString	m_simpleOK;
	CString	m_ANS_participle;
	CString	m_ANS_simple;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIrr_vDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CIrr_vDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onload();
	afx_msg void Onnext();
	afx_msg void Onverify();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int test;
	int count;
	struct data
	{
		CString infinitive;
		CString simple;
		CString participle;
	} *verbs;
	afx_msg void OnBnClickedBrowse();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IRR_VDLG_H__06D6FD4A_C433_472B_B11B_46BD744F9058__INCLUDED_)
