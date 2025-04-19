"use client"; //we are going to use usePathname(), which is a Reach hook to get the user's current path from the URL. 
// React hooks are only avaialble for use in client components. So, we must convert this file into a cleint component.


import {
  UserGroupIcon,
  HomeIcon,
  DocumentDuplicateIcon,
} from '@heroicons/react/24/outline';

import Link from 'next/link';
import { usePathname } from 'next/navigation';
import clsx from 'clsx';
import path from 'path';

// Map of links to display in the side navigation.
// Depending on the size of the application, this would be stored in a database.
const links = [
  { name: 'Home', href: '/dashboard', icon: HomeIcon },
  {
    name: 'Invoices',
    href: '/dashboard/invoices',
    icon: DocumentDuplicateIcon,
  },
  { name: 'Customers', href: '/dashboard/customers', icon: UserGroupIcon },
];

export default function NavLinks() {
  const pathname = usePathname();
  return (
    <>
      {links.map((link) => {
        const LinkIcon = link.icon;
        return (
          <Link 
            //The link componenet is yet another way for page navigation. 
            //Instead of attaching the link to another target page via <a> which is a html syntax, 
            //we use <Link /> which also allows for CLIENT-SIDE NAVIGATION
            // instead of using <a href = "...", we use <Link href = "...">
            //Beforehand, using <a> always resulted in a serverside refreshing of the page for each navigation, ie when we clicked to any of 
            //The other pages in our SideNav component under layout.tsx under dashboard. 
            //Now, using link allows for client side navigation which does not need to refresh page.

            //Accroding to NEXT.js tutorial
            //Save your changes and check to see if it works in your localhost. 
            // You should now be able to navigate between the pages without seeing a full refresh. 
            // Although parts of your application are rendered on the server, there's no full page refresh,
            // making it feel like a native web app. Why is that? 

            //Answer:
            //Next.js automatically prefetches the code for the linked route in the background. 
            // By the time the user clicks the link, the code for the destination page will already be loaded in the background, 
            // and this is what makes the page transition near-instant! Thus, preloading the code for the destination pages means that we do not need to
            //Request from the server everytime to load the page. It is all preloaded thus making things more efficient and localised to client side.

            key={link.name}
            href={link.href}
            className={clsx("flex h-[48px] grow items-center justify-center gap-2 rounded-md bg-gray-50 p-3 text-sm font-medium hover:bg-sky-100 hover:text-blue-600 md:flex-none md:justify-start md:p-2 md:px-3",
            {
              'bg-sky-100 text-blue-600': pathname === link.href, //=== strict equality, checks if the two operators are the same. Javascript syntax
            },
          )}
          >
            <LinkIcon className="w-6" />
            <p className="hidden md:block">{link.name}</p>
          </Link>
        );
      })}
    </>
  );
}
