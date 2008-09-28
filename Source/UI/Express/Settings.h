/*
 * InfraRecorder - CD/DVD burning software
 * Copyright (C) 2006-2008 Christian Kindahl
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include "../../Common/XMLProcessor.h"
#include "../../Common/LNGProcessor.h"

class ISettings
{
public:
	virtual bool Save(CXMLProcessor *pXML) = 0;
	virtual bool Load(CXMLProcessor *pXML) = 0;
};

class CLanguageSettings : public ISettings
{
public:
	TCHAR m_szLanguageFile[MAX_PATH];
	CLNGProcessor *m_pLNGProcessor;

	CLanguageSettings()
	{
		m_szLanguageFile[0] = '\0';
		m_pLNGProcessor = NULL;
	}

	~CLanguageSettings()
	{
		if (m_pLNGProcessor != NULL)
		{
			delete m_pLNGProcessor;
			m_pLNGProcessor = NULL;
		}
	}

	bool Save(CXMLProcessor *pXML);
	bool Load(CXMLProcessor *pXML);
};

extern CLanguageSettings g_LanguageSettings;
