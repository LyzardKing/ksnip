/*
 * Copyright (C) 2020 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef KSNIP_CLIPBOARDWRAPPER_H
#define KSNIP_CLIPBOARDWRAPPER_H

#include <QClipboard>
#include <QPixmap>

class ClipboardWrapper : public QObject
{
	Q_OBJECT
public:
	explicit ClipboardWrapper(QClipboard *clipboard);
	~ClipboardWrapper() override = default;
	QPixmap pixmap() const;
	bool isPixmap() const;
	void setImage(const QImage &image);

signals:
	void changed(bool isPixmap) const;

private:
	QClipboard *mClipboard;

	QString url() const;
};

#endif //KSNIP_CLIPBOARDWRAPPER_H
