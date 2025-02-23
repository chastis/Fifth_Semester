/* It is in this file, specifically the replacePage function that will
   be called by MemoryManagement when there is a page fault.  The 
   users of this program should rewrite PageFault to implement the 
   page replacement algorithm.
*/

  // This PageFault file is an example of the FIFO Page Replacement 
  // Algorithm as described in the Memory Management section.

import java.util.*;
//import Page.*;

public class PageFault {

  /**
   * The page replacement algorithm for the memory management sumulator.
   * This method gets called whenever a page needs to be replaced.
   * <p>
   * The page replacement algorithm included with the simulator is 
   * FIFO (first-in first-out).  A while or for loop should be used 
   * to search through the current memory contents for a canidate 
   * replacement page.  In the case of FIFO the while loop is used 
   * to find the proper page while making sure that virtPageNum is 
   * not exceeded.
   * <pre>
   *   Page page = ( Page ) mem.elementAt( oldestPage )
   * </pre>
   * This line brings the contents of the Page at oldestPage (a 
   * specified integer) from the mem vector into the page object.  
   * Next recall the contents of the target page, replacePageNum.  
   * Set the physical memory address of the page to be added equal 
   * to the page to be removed.
   * <pre>
   *   controlPanel.removePhysicalPage( oldestPage )
   * </pre>
   * Once a page is removed from memory it must also be reflected 
   * graphically.  This line does so by removing the physical page 
   * at the oldestPage value.  The page which will be added into 
   * memory must also be displayed through the addPhysicalPage 
   * function call.  One must also remember to reset the values of 
   * the page which has just been removed from memory.
   *
   * @param mem is the vector which contains the contents of the pages 
   *   in memory being simulated.  mem should be searched to find the 
   *   proper page to remove, and modified to reflect any changes.  
   * @param virtPageNum is the number of virtual pages in the 
   *   simulator (set in Kernel.java).  
   * @param replacePageNum is the requested page which caused the 
   *   page fault.  
   * @param controlPanel represents the graphical element of the 
   *   simulator, and allows one to modify the current display.
   */

  static class Clock
  {
    int hand = 0;
    Vector clockFace = new Vector();
    public Page replacePage(Page newPage)
    {

      //System.out.println( "<clock pages>");
      //for (int i = 0; i < clockFace.size(); i++)
      //{
      //  Page page = ( Page ) clockFace.elementAt( i );
      //  System.out.println( "page :  id =" + page.id + "  r = " + page.R + " phys = " + page.physical );
      //}
      //System.out.println( "</clock pages>");

      while (true)
      {
        if (hand == clockFace.size())
        {
          hand = 0;
        }
        Page page = ( Page ) clockFace.elementAt( hand );
        //System.out.println( "page " + hand + ", r = " + page.R );
          if (page.R == 0)
          {
            clockFace.set(hand, newPage);
            hand++;
            return page;
          }
          else
          {
            page.R = 0;
          }

        hand++;
      }
    }
  }
  static Clock clock = new Clock();
  public static void initClock(Vector mem, int virtPageNum)
  {
    for (int i = 0; i <= virtPageNum; i++)
    {
      Page page = ( Page ) mem.elementAt( i );
      if (page.physical != -1)
      {
        clock.clockFace.addElement(mem.elementAt(i));
      }
    }
  }
  public static void replacePage ( Vector mem , int virtPageNum , int replacePageNum , ControlPanel controlPanel )
  {
    int oldestPage = -1;
    Page nextpage = ( Page ) mem.elementAt( replacePageNum );
    Page oldPage = clock.replacePage(nextpage);


    //System.out.println( "<pages>");
    //for (int i = 0; i <= virtPageNum; i++)
    //{
    //  Page page = ( Page ) mem.elementAt( i );
    //  System.out.println( "page :  id =" + page.id + "  r = " + page.R + " phys = " + page.physical );
    //}
    //System.out.println( "</pages>");

    for (int i = 0; i <= virtPageNum; i++)
    {
      Page page = ( Page ) mem.elementAt( i );
      if (page.id == oldPage.id)
      {
        oldestPage = i;
        break;
      }
    }
    System.out.println( "We replace :" + oldestPage + " to " + replacePageNum );
    controlPanel.removePhysicalPage( oldestPage );
    nextpage.physical = oldPage.physical;
    controlPanel.addPhysicalPage( nextpage.physical , replacePageNum );
    oldPage.inMemTime = 0;
    oldPage.lastTouchTime = 0;
    oldPage.R = 0;
    oldPage.M = 0;
    oldPage.physical = -1;
  }
}
