// -------------------------------------------------------------------------------- //
//	Copyright (C) 2008-2009 J.Rios
//	anonbeat@gmail.com
//
//    This Program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2, or (at your option)
//    any later version.
//
//    This Program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; see the file LICENSE.  If not, write to
//    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
//    http://www.gnu.org/copyleft/gpl.html
//
// -------------------------------------------------------------------------------- //
#ifndef LIBUPDATE_H
#define LIBUPDATE_H

#include "DbLibrary.h"
#include "MainFrame.h"

// -------------------------------------------------------------------------------- //
class guLibUpdateThread : public wxThread
{
  private :
    DbLibrary *         m_Db;
    guMainFrame *       m_MainFrame;
    wxArrayString       m_TrackFiles;
    wxArrayString       m_ImageFiles;
    int                 m_GaugeId;
    wxArrayString       m_LibPaths;
    wxDateTime          m_LastUpdate;
    wxArrayString       m_CoverSearchWords;

    int                 ScanDirectory( wxString dirname );

  public :
    guLibUpdateThread( DbLibrary * db );
    ~guLibUpdateThread();

    guLibUpdateThread::ExitCode Entry();

};

#endif
// -------------------------------------------------------------------------------- //