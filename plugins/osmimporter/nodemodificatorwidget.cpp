/*
Copyright 2010  Christian Vetter veaac.fdirct@gmail.com

This file is part of MoNav.

MoNav is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

MoNav is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with MoNav.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "nodemodificatorwidget.h"
#include "ui_nodemodificatorwidget.h"

NodeModificatorWidget::NodeModificatorWidget( QWidget* parent ) :
		QFrame( parent ),
		m_ui( new Ui::NodeModificatorWidget )
{
	m_ui->setupUi( this );
}

NodeModificatorWidget::~NodeModificatorWidget()
{
	delete m_ui;
}

void NodeModificatorWidget::setModificator( const MoNav::NodeModificator& modificator )
{
	m_ui->type->setCurrentIndex( modificator.invert ? 1 : 0 );
	m_ui->key->setText( modificator.key );
	m_ui->useValue->setChecked( modificator.checkValue );
	if ( modificator.checkValue )
		m_ui->value->setText( modificator.value );
	m_ui->action->setCurrentIndex( ( int ) modificator.type );
	switch ( modificator.type ) {
	case MoNav::NodeModifyFixed:
		m_ui->fixed->setValue( modificator.modificatorValue.toInt() );
		break;
	case MoNav::NodeAccess:
		m_ui->access->setChecked( modificator.modificatorValue.toBool() );
		break;
	}
}

MoNav::NodeModificator NodeModificatorWidget::modificator()
{
	MoNav::NodeModificator result;
	result.invert = m_ui->type->currentIndex() == 1;
	result.key = m_ui->key->text();
	result.checkValue = m_ui->useValue->isChecked();
	if ( result.checkValue )
		result.value = m_ui->value->text();
	result.type = ( MoNav::NodeModificatorType ) m_ui->action->currentIndex();
	switch ( result.type ) {
	case MoNav::NodeModifyFixed:
		result.modificatorValue = m_ui->fixed->value();
		break;
	case MoNav::NodeAccess:
		result.modificatorValue = m_ui->access->isChecked();
		break;
	}
	return result;
}
