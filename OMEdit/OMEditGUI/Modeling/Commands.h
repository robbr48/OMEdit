/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3 LICENSE OR
 * THIS OSMC PUBLIC LICENSE (OSMC-PL) VERSION 1.2.
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES RECIPIENT'S ACCEPTANCE
 * OF THE OSMC PUBLIC LICENSE OR THE GPL VERSION 3, ACCORDING TO RECIPIENTS CHOICE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from OSMC, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or
 * http://www.openmodelica.org, and in the OpenModelica distribution.
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 */
/*
 * @author Adeel Asghar <adeel.asghar@liu.se>
 */

#ifndef COMMANDS_H
#define COMMANDS_H

#include "Modeling/ModelWidgetContainer.h"

class AddShapeCommand : public QUndoCommand
{
public:
  AddShapeCommand(ShapeAnnotation *pShapeAnnotation, QUndoCommand *pParent = 0);
  void redo();
  void undo();
private:
  ShapeAnnotation *mpShapeAnnotation;
};

class UpdateShapeCommand : public QUndoCommand
{
public:
  UpdateShapeCommand(ShapeAnnotation *pShapeAnnotation, QString oldAnnotaton, QString newAnnotation, QUndoCommand *pParent = 0);
  void redo();
  void undo();
private:
  ShapeAnnotation *mpShapeAnnotation;
  QString mOldAnnotation;
  QString mNewAnnotation;
};

class DeleteShapeCommand : public QUndoCommand
{
public:
  DeleteShapeCommand(ShapeAnnotation *pShapeAnnotation, QUndoCommand *pParent = 0);
  void redo();
  void undo();
private:
  ShapeAnnotation *mpShapeAnnotation;
};

class AddComponentCommand : public QUndoCommand
{
public:
  AddComponentCommand(QString name, LibraryTreeItem *pLibraryTreeItem, QString transformationString, QPointF position,
                      QStringList dialogAnnotation, ComponentInfo *pComponentInfo, bool addObject, bool openingClass,
                      GraphicsView *pGraphicsView, QUndoCommand *pParent = 0);
  Component* getComponent() {return mpDiagramComponent;}
  void redo();
  void undo();
private:
  LibraryTreeItem *mpLibraryTreeItem;
  StringHandler::ModelicaClasses mType;
  bool mAddObject;
  ComponentInfo *mpComponentInfo;
  Component *mpIconComponent;
  Component *mpDiagramComponent;
  GraphicsView *mpIconGraphicsView;
  GraphicsView *mpDiagramGraphicsView;
  GraphicsView *mpGraphicsView;
};

class UpdateComponentTransformationsCommand : public QUndoCommand
{
public:
  UpdateComponentTransformationsCommand(Component *pComponent, const Transformation &oldTransformation,
                                        const Transformation &newTransformation, QUndoCommand *pParent = 0);
  void redo();
  void undo();
private:
  Component *mpComponent;
  Transformation mOldTransformation;
  Transformation mNewTransformation;
};

class UpdateComponentAttributesCommand : public QUndoCommand
{
public:
  UpdateComponentAttributesCommand(Component *pComponent, const ComponentInfo &oldComponentInfo, const ComponentInfo &newComponentInfo,
                                   bool duplicate = false, QUndoCommand *pParent = 0);
  void redo();
  void undo();
private:
  Component *mpComponent;
  ComponentInfo mOldComponentInfo;
  ComponentInfo mNewComponentInfo;
  bool mDuplicate;
};

class UpdateComponentParametersCommand : public QUndoCommand
{
public:
  UpdateComponentParametersCommand(Component *pComponent, QMap<QString, QString> oldComponentModifiersMap,
                                   QMap<QString, QString> oldComponentExtendsModifiersMap, QMap<QString, QString> newComponentModifiersMap,
                                   QMap<QString, QString> newComponentExtendsModifiersMap, QUndoCommand *pParent = 0);
  void redo();
  void undo();
private:
  Component *mpComponent;
  QMap<QString, QString> mOldComponentModifiersMap;
  QMap<QString, QString> mOldComponentExtendsModifiersMap;
  QMap<QString, QString> mNewComponentModifiersMap;
  QMap<QString, QString> mNewComponentExtendsModifiersMap;
};

class DeleteComponentCommand : public QUndoCommand
{
public:
  DeleteComponentCommand(Component *pComponent, GraphicsView *pGraphicsView, QUndoCommand *pParent = 0);
  void redo();
  void undo();
private:
  Component *mpComponent;
  Component *mpIconComponent;
  Component *mpDiagramComponent;
  GraphicsView *mpIconGraphicsView;
  GraphicsView *mpDiagramGraphicsView;
  GraphicsView *mpGraphicsView;
  QStringList mParameterNames;
  QStringList mParameterValues;
};

class AddConnectionCommand : public QUndoCommand
{
public:
  AddConnectionCommand(LineAnnotation *pConnectionLineAnnotation, bool addConnection, QUndoCommand *pParent = 0);
  void redo();
  void undo();
private:
  LineAnnotation *mpConnectionLineAnnotation;
  bool mAddConnection;
};

class UpdateConnectionCommand : public QUndoCommand
{
public:
  UpdateConnectionCommand(LineAnnotation *pConnectionLineAnnotation, QString oldAnnotaton, QString newAnnotation, QUndoCommand *pParent = 0);
  void redo();
  void undo();
private:
  LineAnnotation *mpConnectionLineAnnotation;
  QString mOldAnnotation;
  QString mNewAnnotation;
};

class UpdateMetaModelConnection : public QUndoCommand
{
public:
  UpdateMetaModelConnection(LineAnnotation *pConnectionLineAnnotation, MetaModelConnection oldMetaModelConnection,
                            MetaModelConnection newMetaModelConnection, QUndoCommand *pParent = 0);
  void redo();
  void undo();
private:
  LineAnnotation *mpConnectionLineAnnotation;
  MetaModelConnection mOldMetaModelConnection;
  MetaModelConnection mNewMetaModelConnection;
};

class DeleteConnectionCommand : public QUndoCommand
{
public:
  DeleteConnectionCommand(LineAnnotation *pConnectionLineAnnotation, QUndoCommand *pParent = 0);
  void redo();
  void undo();
private:
  LineAnnotation *mpConnectionLineAnnotation;
  GraphicsView *mpGraphicsView;
};

class UpdateCoOrdinateSystemCommand : public QUndoCommand
{
public:
  UpdateCoOrdinateSystemCommand(GraphicsView *pGraphicsView, CoOrdinateSystem oldCoOrdinateSystem, CoOrdinateSystem newCoOrdinateSystem,
                                bool copyProperties, QString oldVersion, QString newVersion, QString oldUsesAnnotationString,
                                QString newUsesAnnotationString, QString oldOMCFlags, QString newOMCFlags, QUndoCommand *pParent = 0);
  void redo();
  void undo();
private:
  GraphicsView *mpGraphicsView;
  CoOrdinateSystem mOldCoOrdinateSystem;
  CoOrdinateSystem mNewCoOrdinateSystem;
  bool mCopyProperties;
  QString mOldVersion;
  QString mNewVersion;
  QString mOldUsesAnnotationString;
  QString mNewUsesAnnotationString;
  QString mOldOMCFlags;
  QString mNewOMCFlags;
};

class UpdateClassAnnotationCommand : public QUndoCommand
{
public:
  UpdateClassAnnotationCommand(LibraryTreeItem *pLibraryTreeItem, QString oldAnnotation, QString newAnnotaiton, QUndoCommand *pParent = 0);
  void redo();
  void undo();
private:
  LibraryTreeItem *mpLibraryTreeItem;
  QString mOldAnnotation;
  QString mNewAnnotation;
};

class UpdateClassSimulationFlagsAnnotationCommand : public QUndoCommand
{
public:
  UpdateClassSimulationFlagsAnnotationCommand(LibraryTreeItem *pLibraryTreeItem, QString oldSimulationFlags, QString newSimulationFlags,
                                              QUndoCommand *pParent = 0);
  void redo();
  void undo();
private:
  LibraryTreeItem *mpLibraryTreeItem;
  QString mOldSimulationFlags;
  QString mNewSimulationFlags;
};

class UpdateSubModelAttributesCommand : public QUndoCommand
{
public:
  UpdateSubModelAttributesCommand(Component *pComponent, const ComponentInfo &oldComponentInfo, const ComponentInfo &newComponentInfo,
                                  QStringList &parameterNames, QStringList &oldParameterValues,
                                  QStringList &newParameterValues, QUndoCommand *pParent = 0);
  void redo();
  void undo();
private:
  Component *mpComponent;
  ComponentInfo mOldComponentInfo;
  ComponentInfo mNewComponentInfo;
  QStringList mParameterNames;
  QStringList mOldParameterValues;
  QStringList mNewParameterValues;
};

class UpdateSimulationParamsCommand : public QUndoCommand
{
public:
  UpdateSimulationParamsCommand(LibraryTreeItem *pLibraryTreeItem, QString oldStartTime, QString newStartTime, QString oldStopTime,
                                QString newStopTime, QUndoCommand *pParent = 0);
  void redo();
  void undo();
private:
  LibraryTreeItem *mpLibraryTreeItem;
  QString mOldStartTime;
  QString mNewStartTime;
  QString mOldStopTime;
  QString mNewStopTime;
};

class AlignInterfacesCommand : public QUndoCommand
{
public:
  AlignInterfacesCommand(MetaModelEditor *pMetaModelEditor, QString fromInterface, QString toInterface, QGenericMatrix<3,1,double> oldPos,
                         QGenericMatrix<3,1,double> oldRot, QGenericMatrix<3,1,double> newPos, QGenericMatrix<3,1,double> newRot,
                         LineAnnotation *pConnectionLineAnnotation, QUndoCommand *pParent = 0);
  void redo();
  void undo();
private:
  MetaModelEditor *mpMetaModelEditor;
  QString mFromInterface;
  QString mToInterface;
  QGenericMatrix<3,1,double> mOldPos;
  QGenericMatrix<3,1,double> mOldRot;
  QGenericMatrix<3,1,double> mNewPos;
  QGenericMatrix<3,1,double> mNewRot;
  LineAnnotation *mpConnectionLineAnnotation;
};

class RenameMetaModelCommand : public QUndoCommand
{
public:
  RenameMetaModelCommand(MetaModelEditor *pMetaModelEditor, QString oldMetaModelName, QString newMetaModelName, QUndoCommand *pParent = 0);
  void redo();
  void undo();
private:
  MetaModelEditor *mpMetaModelEditor;
  QString mOldMetaModelName;
  QString mNewMetaModelName;
};

#endif // COMMANDS_H
