// irr_vDlg.cpp : implementation file
//
/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Irregular verbs.
	This file contains the implementation of main program.
	
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

#include "stdafx.h"
#include "irr_v.h"
#include "irr_vDlg.h"
#include <stdlib.h>
#include <time.h>
#include<string>
#include<fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIrr_vDlg dialog

CIrr_vDlg::CIrr_vDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIrr_vDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIrr_vDlg)
	m_file = _T("");
	m_participle = _T("");
	m_simple = _T("");
	m_infinitive = _T("");
	m_participleOK = _T("");
	m_simpleOK = _T("");
	m_ANS_participle = _T("");
	m_ANS_simple = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIrr_vDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIrr_vDlg)
	DDX_Text(pDX, IDC_file, m_file);
	DDX_Text(pDX, IDC_participle, m_participle);
	DDX_Text(pDX, IDC_simple, m_simple);
	DDX_Text(pDX, IDC_infinitive, m_infinitive);
	DDX_Text(pDX, IDC_participleOK, m_participleOK);
	DDX_Text(pDX, IDC_simpleOK, m_simpleOK);
	DDX_Text(pDX, IDC_ANS_participle, m_ANS_participle);
	DDX_Text(pDX, IDC_ANS_simple, m_ANS_simple);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CIrr_vDlg, CDialog)
	//{{AFX_MSG_MAP(CIrr_vDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_load, Onload)
	ON_BN_CLICKED(IDC_next, Onnext)
	ON_BN_CLICKED(IDC_verify, Onverify)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_Browse, &CIrr_vDlg::OnBnClickedBrowse)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIrr_vDlg message handlers

BOOL CIrr_vDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CIrr_vDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CIrr_vDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CIrr_vDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CIrr_vDlg::Onload() 
{
	UpdateData(TRUE);
	int i,j,k,l;
	char temp[70];
	char temp1[2];
	temp1[1]='\0';
	ifstream ifile(m_file,ios::binary);
	//counting the numbers of verbs
	for(i=0;i<70;i++) temp[i]='\0';
	ifile.getline(temp,70,'\n');
	count=atoi(temp);
	CString tmp;
	tmp.Empty();
	tmp.Format("This file have %d verbs.",count);
	MessageBox(tmp);
	//ifile.seekg(0L,ios::beg);
	verbs=new data[count];
	for(i=0;i<count;i++)
	{
		for(l=0;l<70;l++) temp[l]='\0';
		ifile.getline(temp,70,'\n');
		k=0;
		l=0;
		verbs[i].infinitive.Empty();
		verbs[i].simple.Empty();
		verbs[i].participle.Empty();
		for(j=0;temp[j]!='\0'&&temp[j]!='\r';j++)
		{
			if(temp[j]!=' ')
			{
				temp1[0]=temp[j];
				if(k==0)		verbs[i].infinitive.Insert(l,temp1);
				else if(k==1)	verbs[i].simple.Insert(l,temp1);
				else if(k==2)	verbs[i].participle.Insert(l,temp1);
				else
				{
					MessageBox("Error in file");
					ifile.close();
					return;
				}
				l++;
			}
			else { k++; l=0;}
		}
	}
	ifile.close();
	srand( (unsigned)time( NULL ) );
}

void CIrr_vDlg::Onnext() 
{
	test=rand()%count;
	m_infinitive.Empty();
	m_infinitive.Insert(0,verbs[test].infinitive);
	m_participle.Empty();
	m_simple.Empty();
	m_simpleOK.Empty();
	m_participleOK.Empty();
	m_ANS_participle.Empty();
	m_ANS_simple.Empty();
	UpdateData(FALSE);
}

void CIrr_vDlg::Onverify() 
{
	UpdateData(TRUE);
	m_participleOK.Empty();
	m_participleOK.Insert(0,verbs[test].participle);
	m_simpleOK.Empty();
	m_simpleOK.Insert(0,verbs[test].simple);
	m_ANS_simple.Empty();
	m_ANS_participle.Empty();
	bool flagp=true;
	bool flags=true;
	CString message;
	message.Empty();
	if(m_participleOK.Compare(m_participle)!=0)
	{
		m_ANS_participle.Insert(0,"WRONG");
		message.Insert(0,"Past Participle is wrong\n");
		flagp=false;
	}
	else m_ANS_participle.Insert(0,"RIGHT");
	if(m_simpleOK.Compare(m_simple)!=0)
	{
		m_ANS_simple.Insert(0,"WRONG");
		message.Insert(0,"Past Simple is wrong\n");
		flags=false;
	}
	else m_ANS_simple.Insert(0,"RIGHT");
	UpdateData(FALSE);
	if(flagp==false || flags==false) MessageBox(message);
}

void CIrr_vDlg::OnBnClickedBrowse()
{
	CFileDialog fileDialog(TRUE);
	fileDialog.DoModal();
	CString temp=fileDialog.GetPathName();
	m_file.Empty();
	m_file.Insert(0,temp);
	UpdateData(FALSE);
}
