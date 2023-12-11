/*****************************************************************************
 * MeshLab                                                           o o     *
 * Visual and Computer Graphics Library                            o     o   *
 *                                                                _   O  _   *
 * Copyright(C) 2004-2022                                           \/)\/    *
 * Visual Computing Lab                                            /\/|      *
 * ISTI - Italian National Research Council                           |      *
 *                                                                    \      *
 * All rights reserved.                                                      *
 *                                                                           *
 * This program is free software; you can redistribute it and/or modify      *
 * it under the terms of the GNU General Public License as published by      *
 * the Free Software Foundation; either version 2 of the License, or         *
 * (at your option) any later version.                                       *
 *                                                                           *
 * This program is distributed in the hope that it will be useful,           *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 * GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
 * for more details.                                                         *
 *                                                                           *
 ****************************************************************************/

#include "open_file_widget.h"

#include <QFileDialog>

OpenFileWidget::OpenFileWidget(
	QWidget*            p,
	const RichFileOpen& param,
	const StringValue&  defaultValue) :
		IOFileWidget(p, param, defaultValue), extensions(param.exts.join(";;"))
{
}

OpenFileWidget::~OpenFileWidget()
{
}

void OpenFileWidget::selectFile()
{
	QString path = QDir::homePath();
	if (!filename->text().isEmpty())
		path = filename->text();
	QString fl = QFileDialog::getOpenFileName(this, tr("Open"), path, extensions);
	if (!fl.isEmpty()) {
		updateFileName(fl);
		emit dialogParamChanged();
	}
}
