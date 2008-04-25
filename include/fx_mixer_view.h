/*
 * fx_mixer_view.h - effect-mixer-view for LMMS
 *
 * Copyright (c) 2008 Tobias Doerffel <tobydox/at/users.sourceforge.net>
 * 
 * This file is part of Linux MultiMedia Studio - http://lmms.sourceforge.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */


#ifndef _FX_MIXER_VIEW_H
#define _FX_MIXER_VIEW_H

#include <QtGui/QWidget>

#include "fx_mixer.h"


class QStackedLayout;
class QButtonGroup;
class fader;
class fxLine;
class effectRackView;
class pixmapButton;



class fxMixerView : public QWidget, public modelView
{
	Q_OBJECT
public:
	fxMixerView();
	virtual ~fxMixerView();

	fxLine * currentFxLine( void )
	{
		return( m_currentFxLine );
	}
	void setCurrentFxLine( fxLine * _line );
	void setCurrentFxLine( int _line );

	void clear( void );


private slots:
	void updateFaders( void );


private:
	struct fxChannelView
	{
		fxLine * m_fxLine;
		effectRackView * m_rackView;
		pixmapButton * m_muteButton;
		pixmapButton * m_soloButton;
		fader * m_fader;
	} ;

	fxChannelView m_fxChannelViews[NumFxChannels+1];

	QStackedLayout * m_fxRacksLayout;
	QStackedLayout * m_fxLineBanks;
	QButtonGroup * m_bankButtons;
	fxLine * m_currentFxLine;

} ;

#endif
