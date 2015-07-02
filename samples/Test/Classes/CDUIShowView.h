//
//  CDUIShowView.h
//  Test
//
//  Created by renhongguang on 15/4/7.
//
//

#ifndef __Test__CDUIShowView__
#define __Test__CDUIShowView__

#include "RootWindow.h"

using namespace CSJson;

class Info :public CAObject
{
public:
    std::string name;
    std::string uid;
    std::string gender;
    std::string occupation;
};

class jsonWriter : Writer
{
    
};

class CDETableViewDelegate
{
public:
    
    virtual ~CDETableViewDelegate(){};
    
    virtual void etableViewDidSelectRowAtIndexPath(CATableView* table, unsigned int section, unsigned int row){};
    
    virtual void etableViewDidDeselectRowAtIndexPath(CATableView* table, unsigned int section, unsigned int row){};
};

class ETableViewCell : public CATableViewCell
{
public:
    ETableViewCell();
    virtual ~ETableViewCell();
    static ETableViewCell* create(const std::string& identifier, const CADipRect& _rect = CADipRectZero);
    virtual void highlightedTableViewCell();
    virtual void selectedTableViewCell();
public:
    void initWithCell();
};

class ETableView : public CAView,CATableViewDelegate, CATableViewDataSource
{
public:
    ETableView();
    virtual ~ETableView();
    
    virtual bool init(const CrossApp::CCRect &rect);
    static ETableView* createWithFrame(const CCRect& rect);
    static ETableView* createWithCenter(const CCRect& rect);
    
public:
    virtual void tableViewDidSelectRowAtIndexPath(CATableView* table, unsigned int section, unsigned int row);
    virtual void tableViewDidDeselectRowAtIndexPath(CATableView* table, unsigned int section, unsigned int row);
    
    virtual CATableViewCell* tableCellAtIndex(CATableView* table, const CCSize& cellSize, unsigned int section, unsigned int row);
    virtual unsigned int numberOfRowsInSection(CATableView *table, unsigned int section);
    virtual unsigned int numberOfSections(CATableView *table);
    virtual unsigned int tableViewHeightForRowAtIndexPath(CATableView* table, unsigned int section, unsigned int row);
    virtual unsigned int tableViewHeightForHeaderInSection(CATableView* table, unsigned int section);
    virtual unsigned int tableViewHeightForFooterInSection(CATableView* table, unsigned int section);
    
    CC_SYNTHESIZE(CDETableViewDelegate*, m_pETableViewDelegate, ETableViewDelegate);
public:
    CATableView* p_TableView;
    CADipSize size;
};

class CDListView : public CAView ,CAListViewDelegate,CAListViewDataSource
{
public:
    CDListView();
    virtual ~CDListView();
    
    virtual bool init(const CrossApp::CCRect &rect);
    static CDListView* createWithFrame(const CCRect& rect);
    static CDListView* createWithCenter(const CCRect& rect);
    
public:
    virtual void listViewDidSelectCellAtIndex(CAListView *listView, unsigned int index);
    virtual void listViewDidDeselectCellAtIndex(CAListView *listView, unsigned int index);
    virtual unsigned int numberOfIndex(CAListView *listView);
    virtual unsigned int listViewHeightForIndex(CAListView *listView, unsigned int index);
    virtual CAListViewCell* listViewCellAtIndex(CAListView *listView, const CCSize& cellSize, unsigned int index);
public:
    std::vector<std::string> tempList;
};

class CDUIShowView :
public CAViewController,
public CATableViewDelegate,
public CATableViewDataSource,
public CAListViewDelegate,
public CAListViewDataSource,
public CAPageViewDelegate,
public CDETableViewDelegate,
public CACollectionViewDelegate,
public CACollectionViewDataSource,
public CAScrollViewDelegate,
public CAPickerViewDelegate,
public CAPickerViewDataSource,
public CADatePickerViewDelegate,
public CAVideoPlayerControllerDelegate
{
public:
    
    CDUIShowView();
    
    virtual ~CDUIShowView();
protected:
    
    void viewDidLoad();
    
    void viewDidUnload();
    
public:
    
    void showUiWithIndex(int _index);
    
    void initButtonControl();
    void buttonControlCallBack(CAControl* btn,CCPoint point);
    
    void showAlertView();
    void alertCallBack(int btnIndex);
    void alertButtonCallBack(CAControl* btn,CCPoint point);
    void setAlertViewNavigationBarTitle();
    
    void showButton();
    void showButtonByIndex();
    void buttonCallBack(CAControl* btn,CCPoint point);
    
    void showImage();
    void showImageByIndex();
    
    void showScale9Image();
    
    void showIndicator();
    void showIndicatorByIndex();
    
    void showLabel();
    void showLabelByIndex();
    
    void showProgress();
    void progressValueChange(float _t);
    
    void showSlider();
    void showSliderByindex();
    void sliderValueChange(CAControl* btn, CCPoint point);
    
    void showSwitch();
    void showSwitchByIndex();
    void switchStateChange(CAControl* btn, CCPoint point);
    
    void showTextField();
    void showTextFieldByIndex();
    
    void showSegmentedControl();
    void showSegmentedControlByIndex();
    void segmentCallback(CASegmentedControl* btn, int index);
    
    void showTabBar();
    
    void showPageView();
    
    void showTextView();
    
    void showTableView();
    
    void showListView();
    
    void showWebView();
    
    void showCollectionView();
    
    void showScrollView();
    
    void showFlashView();
    
    void showAnimation();
    void doAction(CAControl* btn,CCPoint point);
    
    void showDatePickerView();
    
    void showStepper();
    void stepperCallBack(CAControl* btn,CCPoint point);
    
    void showGifView();
    
    void showVideo();
    
    void showRenderImage();
    void renderCallBack();
    void scheduleFuck();
    
    void jsonTest();//json数据读写
    
    void httpTest();
    
    void DownLoadManageTest();
    
    void DeviceTest();
    
    void requestResult(CAHttpClient* client, CAHttpResponse* response);
    
public:
    //TableView
    virtual void tableViewDidSelectRowAtIndexPath(CATableView* table, unsigned int section, unsigned int row);
    virtual void tableViewDidDeselectRowAtIndexPath(CATableView* table, unsigned int section, unsigned int row);
    
    virtual CATableViewCell* tableCellAtIndex(CATableView* table, const CCSize& cellSize, unsigned int section, unsigned int row);
    virtual CAView* tableViewSectionViewForHeaderInSection(CATableView* table, const CCSize& viewSize, unsigned int section);
    virtual CAView* tableViewSectionViewForFooterInSection(CATableView* table, const CCSize& viewSize, unsigned int section);
    virtual unsigned int numberOfRowsInSection(CATableView *table, unsigned int section);
    virtual unsigned int numberOfSections(CATableView *table);
    virtual unsigned int tableViewHeightForRowAtIndexPath(CATableView* table, unsigned int section, unsigned int row);
    virtual unsigned int tableViewHeightForHeaderInSection(CATableView* table, unsigned int section);
    virtual unsigned int tableViewHeightForFooterInSection(CATableView* table, unsigned int section);
    
    virtual void etableViewDidSelectRowAtIndexPath(CATableView* table, unsigned int section, unsigned int row);
    void pageControlCallBack(CrossApp::CAControl *btn, CrossApp::CCPoint point);
public:
    //ListView
    virtual void listViewDidSelectCellAtIndex(CAListView *listView, unsigned int index);
    virtual void listViewDidDeselectCellAtIndex(CAListView *listView, unsigned int index);
    virtual unsigned int numberOfIndex(CAListView *listView);
    virtual unsigned int listViewHeightForIndex(CAListView *listView, unsigned int index);
    virtual CAListViewCell* listViewCellAtIndex(CAListView *listView, const CCSize& cellSize, unsigned int index);
public:
    //pageView
    virtual void reshapeViewRectDidFinish();
    
    virtual void pageViewDidBeginTurning(CAPageView* pageView);
    virtual void pageViewDidEndTurning(CAPageView* pageView);
    virtual void pageViewDidSelectPageAtIndex(CAPageView* pageView, unsigned int index, const CCPoint& point);
public:
    //CollectionView
    virtual void collectionViewDidSelectCellAtIndexPath(CACollectionView *collectionView, unsigned int section, unsigned int row, unsigned int item);
    virtual void collectionViewDidDeselectCellAtIndexPath(CACollectionView *collectionView, unsigned int section, unsigned int row, unsigned int item);
    
    virtual CACollectionViewCell* collectionCellAtIndex(CACollectionView *collectionView, const CCSize& cellSize, unsigned int section, unsigned int row, unsigned int item);
    virtual unsigned int numberOfSections(CACollectionView *collectionView);
    virtual unsigned int numberOfRowsInSection(CACollectionView *collectionView, unsigned int section);
    virtual unsigned int numberOfItemsInRowsInSection(CACollectionView *collectionView, unsigned int section, unsigned int row);
    virtual unsigned int collectionViewHeightForRowAtIndexPath(CACollectionView* collectionView, unsigned int section, unsigned int row);
    
    virtual void scrollViewHeaderBeginRefreshing(CAScrollView* view);
    virtual void scrollViewFooterBeginRefreshing(CAScrollView* view);
    void refreshData(float interval);
public:
    void zoomViewBySliderValue(CAControl* btn,CCPoint point);
public:
    //CAPickerView
    virtual unsigned int numberOfComponentsInPickerView(CAPickerView* pickerView);
    virtual unsigned int numberOfRowsInComponent(CAPickerView* pickerView, unsigned int component);
    virtual float widthForComponent(CAPickerView* pickerView, unsigned int component);
    virtual float rowHeightForComponent(CAPickerView* pickerView, unsigned int component);
    virtual CCString* titleForRow(CAPickerView* pickerView, unsigned int row, unsigned int component);
    
    virtual void didSelectRow(CAPickerView* pickerView, unsigned int row, unsigned int component);
    virtual void didSelectRow(const struct tm& tm);
public:
    virtual void onVideoPlayerButtonBack();
public:
    
    std::vector<std::string> testList;
    CADipSize winSize;
    CALabel* progress_value;
    CAProgress* progress;
    CALabel* sliderValue1;
    CALabel* sliderValue2;
    CASlider* slider;
    CALabel* switchState;
    CALabel* segmentPage;
    CATableView* p_TableView;
    CAListView* p_ListView;
    CAPageView* p_pageView;
    CAPageView* p_PageViewVec;
    CAPageControl* pageControl;
    CAScrollView* p_ScrollView;
    CACollectionView* p_Conllection;
    CAPullToRefreshView* headerRefreshView;
    CAPullToRefreshView* footerRefreshView;
    std::vector<CAColor4B> colorArr;
    CAImageView* p_imageView;
    CAPickerView* p_pickerView;
    CALabel* city_value;
    CAImageView* animationView;
    CAStepper* step;
    CALabel* step_value;
    CAImageView* renderImage;
    
    int UIINDEX;
    int showIndex;
    int showNum;
    int pageViewIndex;
    int heart_index;
    int dle_ren_index;
    CAVector<CAView* > VIEWLIST;
};

#endif /* defined(__Test__CDUIShowView__) */
