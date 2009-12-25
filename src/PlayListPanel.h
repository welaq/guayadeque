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
#ifndef PLAYLISTPANEL_H
#define PLAYLISTPANEL_H

#include "DbLibrary.h"
#include "PlayerPanel.h"
#include "PLSoListBox.h"
#include "SoListBox.h"


#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/statline.h>
#include <wx/listctrl.h>
#include <wx/splitter.h>
#include <wx/frame.h>
#include <wx/treectrl.h>
#include <wx/imaglist.h>

// -------------------------------------------------------------------------------- //
// guPLNamesTreeCtrl
// -------------------------------------------------------------------------------- //
class guPLNamesTreeCtrl : public wxTreeCtrl
{
  protected :
    DbLibrary *     m_Db;
    wxImageList *   m_ImageList;
    wxTreeItemId    m_RootId;
    wxTreeItemId    m_StaticId;
    wxTreeItemId    m_DynamicId;

    void            OnContextMenu( wxTreeEvent &event );
    void            OnBeginDrag( wxTreeEvent &event );

  public :
    guPLNamesTreeCtrl( wxWindow * parent, DbLibrary * db );
    ~guPLNamesTreeCtrl();

    void            ReloadItems( void );

    DECLARE_EVENT_TABLE()
};

// -------------------------------------------------------------------------------- //
class guPlayListPanel : public wxPanel
{
  private :
    DbLibrary *         m_Db;
    guPlayerPanel *     m_PlayerPanel;

    wxSplitterWindow *  m_MainSplitter;
    guPLNamesTreeCtrl * m_NamesTreeCtrl;
    guPLSoListBox *     m_PLTracksListBox;

    void                OnPLNamesSelected( wxTreeEvent &event );
    void                OnPLNamesActivated( wxTreeEvent &event );
    void                OnPLNamesPlay( wxCommandEvent &event );
    void                OnPLNamesEnqueue( wxCommandEvent &event );
    void                OnPLNamesNewPlaylist( wxCommandEvent &event );
    void                OnPLNamesEditPlaylist( wxCommandEvent &event );
    void                OnPLNamesRenamePlaylist( wxCommandEvent &event );
    void                OnPLNamesDeletePlaylist( wxCommandEvent &event );
    void                OnPLNamesCopyTo( wxCommandEvent &event );

    void                OnPLTracksActivated( wxListEvent &event );
    void                OnPLTracksDeleteClicked( wxCommandEvent &event );
    void                OnPLTracksPlayClicked( wxCommandEvent &event );
    void                OnPLTracksPlayAllClicked( wxCommandEvent &event );
    void                OnPLTracksQueueClicked( wxCommandEvent &event );
    void                OnPLTracksQueueAllClicked( wxCommandEvent &event );
    void                OnPLTracksEditLabelsClicked( wxCommandEvent &event );
    void                OnPLTracksEditTracksClicked( wxCommandEvent &event );
    void                OnPLTracksCopyToClicked( wxCommandEvent &event );
    void                OnPLTracksSavePlayListClicked( wxCommandEvent &event );

    void                OnPLTracksSelectGenre( wxCommandEvent &event );
    void                OnPLTracksSelectArtist( wxCommandEvent &event );
    void                OnPLTracksSelectAlbum( wxCommandEvent &event );

    void                MainSplitterOnIdle( wxIdleEvent &event );

  public :
    guPlayListPanel( wxWindow * parent, DbLibrary * db, guPlayerPanel * playerpanel );
    ~guPlayListPanel();

    void                PlayListUpdated( void );

};

#endif
// -------------------------------------------------------------------------------- //
