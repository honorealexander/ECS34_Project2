# CXMLWriter

CXMLWriter provides feasibility for writing XML data. It uses the Expat XML parser.

## Structure

### Constructor

SImplementation(std::shared_ptr<CDataSink> sink)

Parameters: sink
This is a shared pointer to CDataSink which is an object that is the destination for writing the XML data.

This initializes the SImplementation structure and creates an instance of the Expat XML parser.

### Destructor

~SImplementation()

The destructor does not take any paremeters but frees any memory from the Expat parser. This is useful for making sure that there are no leaks.

### Flush

bool Flush()

Flush makes sure that any remaining data from the Expat parser is processed. It returns true if the flush was successful.

This method is called when the writing process has completed.

### WriteEntity

bool WriteEntity(const SXMLEntity& entity)

This writes the XML entity onto the data sink
The entity can be StartElement, EndElement, or CharData

Parameters: entity

## CXMLWriter Class

### Constructor

CXMLWriter(std::shared_ptr<CDataSink> sink)

This initializes CXMLWriter's class according to whatever data sink has been specified.

This takes the parameter 'sink' which is a shared pointer to CDataSink's object which represents the XML writing data destination.

### Destructor

~CXMLWriter() = default;

This is the default destuctor. It has been marked as default to indicate that it uses default behavior for destructors which has been provided by the compiler.

This automatically calls the destructor of the DImplementation member which frees anythign associated with the Expat Parser.

### Flush

bool Flush()

This invokes the flush method to flush the Expat parser data.
Returns true if it was flushed.

### WriteEntity

bool WriteEntity(const SXMLEntity &entity)

This takes the entity parameter which is a reference to SXMLEntity's object that represents the XML entity that we are writing on, and returns true if the writing was successful.