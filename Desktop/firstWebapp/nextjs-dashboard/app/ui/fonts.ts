import {Inter} from "next/font/google";
//import a secodnary font
import { Lusitana } from "next/font/google";

export const inter = Inter({subsets:['latin']}); //load the latin glyphs from the Inter font space, to be used. 
// This is called subsetting, whereby we choose to take a particular set of glyphs/syntax out of the entire universal lexicon 
// covered by Inter. For instance, there are chinese, korean characters as well but of course we use the latin alphabet first.
export const lusitana = Lusitana({subsets:['latin'], weight:["700"]})