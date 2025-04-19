// a file to define the styling of this paage, called layout.tsx

import React from "react";
import SideNav from "../ui/dashboard/sidenav";//importing the sidenav component.This is a sidenave bar that allows u to toggle between the different pages!!!!

export default function Layout({children}:{children:React.ReactNode})
//Hence, this layout will be applied to all of the children / leaves under dashbaord,
// which is the customers and invocies page!
//Layout file is the way to create a shared layout that all paged in the application can use, depending on the nesting of this file!!!
{
    // return(
    //     <div className="flex h-screen flex-col md:flex-row md:overflow-hidden"> 
    //     {/*means that create a flexbox, for screen sizes >= md which is 48rem (md:(what to do here)--> 
    //     flex row meaning the rows will automatically wrap when the screen window is shrunk/smth, 
    //     and hide any overflow. No overflow)*/}
    //     <div className="w-full flex-none md: w-64">
    //         <SideNav />
    //     </div>
    //     <div className="flex-grow p-6 md:overflow-y-auto md:p-12">{children}</div>
    //     </div>
    // );

    return(
        <div className="flex flex-col md:flex-row md:h-screen md:overflow-hidden"> 
    {/* Sidebar - fixed width on md+ screens, full width on mobile */}
    <div className="w-full md:w-64 flex-none">
        <SideNav />
    </div>
    
    {/* Main content - grows to fill space, scrollable if needed */}
    <div className="flex-1 p-6 md:overflow-y-auto md:p-12">
        {children}
    </div>
    </div>);
}