//#include "StdAfx.h"

#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>

// Cette methode recursive permet d'afficher la liste de test enregistres aupres de CPP UNIT
static void printTests(CPPUNIT_NS::Test * ai_test) {
    // Si le test existe
    if (ai_test) {
        // Si le Test a des fils
        if (ai_test->getChildTestCount() > 0) {
            // On parcours les fils recursivement
            for (int w_i = 0; w_i < ai_test->getChildTestCount(); w_i++) {
                printTests(ai_test->getChildTestAt(w_i));
            }
        }
        else {
            // Sinon print le nom du test
            std::cout << ai_test->getName() << std::endl;
        }
    }                           // Sinon on fait rien
}

int main(int argc, char **argv) {
    // Create the event manager and test controller
    CPPUNIT_NS::TestResult controller;

    // Add a listener that colllects test result
    CPPUNIT_NS::TestResultCollector result;
    controller.addListener(&result);

    // Add a listener that print dots as test run.
    CPPUNIT_NS::BriefTestProgressListener progress;
    controller.addListener(&progress);

    // Add the top suite to the test runner
    CPPUNIT_NS::TestRunner runner;
    CPPUNIT_NS::Test * tests =
        CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();
    runner.addTest(tests);

    //Display
    if (argc >= 2) {
        std::string w_param(argv[1]);
        // Si l'aide est demandée, on affiche la liste des tests enregistres
        if (w_param == "-h") {
            std::cout << "-> Tests list" << std::endl;
            //Appelle la methode locale du main printTest
            printTests(tests);
            std::cout << "/!\\ No tests will be executed" << std::endl;
        }
        else                    // Sinon on execute les tests specifies en arguments
        {
            //pour chaque nom de test donne en argument, essaye de le lancer. Si le lancement echoue, une exception est printe
            for (int w_i = 1; w_i < argc; w_i++) {
                // Run le test selectionne, si aucun test est selectionne, run tout
                try {
                    std::cout << "-> Launch test : " << argv[w_i] << std::endl;
                    runner.run(controller, argv[w_i]);
                }
                catch(std::exception & e) {
                    std::cout << "/!\\ Exception catch { " << e.
                        what() << " }" << std::endl;
                }
            }
        }
    }
    else                        //Sinon tous les tests sont executes
    {
        std::cout << "-> Launch all tests" << std::endl;
        runner.run(controller);
    }

    // Print test in a compiler compatible format.
    CPPUNIT_NS::CompilerOutputter outputter(&result, CPPUNIT_NS::stdCOut());
    outputter.write();

    // Return error code 1 if the one of test failed.
    return result.wasSuccessful()? 0 : 1;
}
