//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "MooseRBE3TestApp.h"
#include "MooseRBE3App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
MooseRBE3TestApp::validParams()
{
  InputParameters params = MooseRBE3App::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

MooseRBE3TestApp::MooseRBE3TestApp(InputParameters parameters) : MooseApp(parameters)
{
  MooseRBE3TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

MooseRBE3TestApp::~MooseRBE3TestApp() {}

void
MooseRBE3TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  MooseRBE3App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"MooseRBE3TestApp"});
    Registry::registerActionsTo(af, {"MooseRBE3TestApp"});
  }
}

void
MooseRBE3TestApp::registerApps()
{
  registerApp(MooseRBE3App);
  registerApp(MooseRBE3TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
MooseRBE3TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MooseRBE3TestApp::registerAll(f, af, s);
}
extern "C" void
MooseRBE3TestApp__registerApps()
{
  MooseRBE3TestApp::registerApps();
}
