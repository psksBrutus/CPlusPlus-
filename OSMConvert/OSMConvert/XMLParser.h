//
//  XMLParser.h
//  OSM_Konverter
//
//  Created by Marcel Radischat on 01.06.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#include <iostream>
#include <exception>
#include "expat.h"

namespace xml
{
	namespace parse
	{
		
		class ParserCallback
		{
		public:
			virtual void startElement( const char *name, const char **atts) = 0;
			virtual void endElement( const char *name) = 0;
		};
		
		class Parser
		{
		public:
			// Rückgabe: Fehlernummer, 0 ist ok
			static int Parse( ParserCallback& callback, const char* fileName );
			~Parser();
		};
		
		
		using namespace std;
		
		class ParserException : exception{
		public:
			ParserException(XML_Parser& parser, FILE* fp ) : exception(){}
			
            
            friend ostream& operator<<( ostream& os, const ParserException& e){
                return os << e.what();
            }

            
		};
		
	} // end namespace parse
} // end namespace xml
