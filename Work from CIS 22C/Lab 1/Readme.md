Create a currency class (and any derived classes you may need for up to 5 individual currencies) with four attributes - currency name, whole parts and fractional parts and fractional's name such that 100 fractional parts equals 1 whole part, e.g. Pound, 1, 55, pence or Euro, 3, 33, cent. 

Define overloaded operators to add or subtract different currency objects - care should be taken that you can only perform these operation on objects of the same currency. Also, take care that fractional parts roll into whole parts.

Define an overloaded input stream operator to accept values of any currency as well as an overloaded output stream operator to write out the value of the currency..

Initialize your currency objects demonstrating polymorphic construction.  Your constructors should also use initialization lists.

Define a Wallet class that will contain the 5 individual currency types you define and will implement the following - number of individual currency types, check if a currency type exists in the wallet, add money by currency, remove money by currency, remove all currencies, check if wallet is empty.

To add or remove money into/from wallet, check if currency exists in the wallet.  If so, add or remove the amount specified.

Your main should allow the user to add a maximum of 5 different currency types to the wallet in the form of the base currency array - some examples are Dollar and cent, Euro and cent, Pound and pence, Ruble and kopeck.  User should be able to add as many currency values for any of the five currency types.  You can think about using ENUMs for the currency types to be generated.  The user should also be able to output the total value and name of the currencies in the wallet.  Finally they should be able to empty the wallet and print relevant information about the operation.  User Interactivity is extremely important - give due consideration to it.

Make any relevant assumptions that you may need but state them clearly in your name/comment block at the top.  Remember to document your methods adequately as well as any other relevant comments.  This program will need individual definition and implementation files for the currency and wallet classes and a file for your main, though you may combine various currencies into the same set of files.  

Grade: 15/20

Feedback: -5 currency should not derive from wallet as wallet is supposed to contain currencies, no currency inheritance, polymorphism
