#include "meeseApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
meeseApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

meeseApp::meeseApp(InputParameters parameters) : MooseApp(parameters)
{
  meeseApp::registerAll(_factory, _action_factory, _syntax);
}

meeseApp::~meeseApp() {}

void 
meeseApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<meeseApp>(f, af, s);
  Registry::registerObjectsTo(f, {"meeseApp"});
  Registry::registerActionsTo(af, {"meeseApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
meeseApp::registerApps()
{
  registerApp(meeseApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
meeseApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  meeseApp::registerAll(f, af, s);
}
extern "C" void
meeseApp__registerApps()
{
  meeseApp::registerApps();
}
