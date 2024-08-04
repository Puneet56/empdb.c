# Zero2Hero Database Project

The purpose of this page is to document requirements for the Zero2Hero database project.

## Employee Database

- Store information about employees
- Name
- Address
- Hours Worked
- Add employees to the database
- Update employees in the database
- Store all this information to a file
- Load and edit the database file
- Search the database by name, address, or hours

## My Design

- Read file using file descriptor.
- Store data as binary with some header info.
- Parse file into array of structs.
- For search get from cli args the search term.
- Loop over array of structs and put index of search results in a result array.
- Print structs in a table.
- Store info using args also, take in csv data `name|address|hours`.
- Same approach with update. Reuse search logic
- Use a flag to update complete employee or fields to update particular field.
