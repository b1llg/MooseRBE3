#include "MooseRBE3App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
MooseRBE3App::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

MooseRBE3App::MooseRBE3App(InputParameters parameters) : MooseApp(parameters)
{
  MooseRBE3App::registerAll(_factory, _action_factory, _syntax);
}

MooseRBE3App::~MooseRBE3App() {}

void 
MooseRBE3App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<MooseRBE3App>(f, af, s);
  Registry::registerObjectsTo(f, {"MooseRBE3App"});
  Registry::registerActionsTo(af, {"MooseRBE3App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
MooseRBE3App::registerApps()
{
  registerApp(MooseRBE3App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
MooseRBE3App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MooseRBE3App::registerAll(f, af, s);
}
extern "C" void
MooseRBE3App__registerApps()
{
  MooseRBE3App::registerApps();
}
