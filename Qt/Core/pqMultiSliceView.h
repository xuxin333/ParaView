/*=========================================================================

  Program:   Visualization Toolkit
  Module:    pqMultiSliceView.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME pqMultiSliceView - QT GUI that allow multi slice control

#ifndef __pqMultiSliceView_h
#define __pqMultiSliceView_h

#include "pqCoreModule.h"
#include "pqRenderView.h"

#include <QtCore>
#include <QtGui>

class pqMultiSliceAxisWidget;

class PQCORE_EXPORT pqMultiSliceView : public pqRenderView
{
  Q_OBJECT
  typedef pqRenderView Superclass;
public:
  static QString multiSliceViewType() { return "MultiSlice"; }
  static QString multiSliceViewTypeName() { return "Slice View"; }

  /// constructor takes a bunch of init stuff and must have this signature to
  /// satisfy pqView
  pqMultiSliceView( const QString& viewtype,
                    const QString& group,
                    const QString& name,
                    vtkSMViewProxy* viewmodule,
                    pqServer* server,
                    QObject* p);
  virtual ~pqMultiSliceView();

  /// Override to decorate the QVTKWidget
  virtual QWidget* createWidget();

public slots:
  void updateAxisBounds();
  void updateAxisBounds(double bounds[6]);
  void updateSlices();

protected:
  void updateViewModelCallBack(vtkObject*,unsigned long, void*);

  /// Helper method to get the concreate 3D widget
  QVTKWidget* getInternalWidget() { return this->InternalWidget; }

  QVTKWidget* InternalWidget;
  bool UserIsInteracting;
  QPointer<pqMultiSliceAxisWidget> AxisX;
  QPointer<pqMultiSliceAxisWidget> AxisY;
  QPointer<pqMultiSliceAxisWidget> AxisZ;

  QMap<pqRepresentation*, unsigned int> ObserverIdX;
  QMap<pqRepresentation*, unsigned int> ObserverIdY;
  QMap<pqRepresentation*, unsigned int> ObserverIdZ;

private:
  pqMultiSliceView(const pqMultiSliceView&); // Not implemented.
  void operator=(const pqMultiSliceView&); // Not implemented.
};

#endif